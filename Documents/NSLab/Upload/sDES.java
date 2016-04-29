
/*
 * Rashmi Chennagiri
 * BE H 14
 * 121141
 * NS Lab 6 - Simplified DES
 * 
 */


public class sDES {

    int[] P = {1, 0, 1, 0, 0, 1, 0, 1}; // 8 bit plain text
    int[] C = new int[8]; // ciphered text

    int[] K1 = new int[8];
    int[] K2 = new int[8];

    int[] afterIP = new int[8];
    int[] afterEP = new int[8];
    int[] afterXOR = new int[8];
    int[] afterSBOX = new int[4];
    int[] afterP4 = new int[4];
    int[] afterXOR2 = new int[4];
    int[] newAfterIP = new int[8];
    int[] newAfterIP2 = new int[8];
    int[] afterIP_Inv = new int[8];

    public void keys() {

        int[] K = {0, 0, 1, 0, 0, 1, 0, 1, 1, 1}; // 10 bit key
        int[] P10 = {2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
        int[] P8 = {5, 2, 6, 3, 7, 4, 9, 8};

        int[] NK = new int[10];
        int[] K1t = new int[10];
        int[] K2t = new int[10];

        // 1. Apply P10
        for (int c = 0; c < 10; c++) {
            NK[c] = K[P10[c]];
        }

        System.out.println("\n\nAfter P10: ");
        printArray(NK);

        // 2. LS1
        int t1 = NK[0], c1;
        for (c1 = 0; c1 < 4; c1++) {
            K1t[c1] = NK[c1 + 1];
        }
        K1t[c1] = t1;

        int t2 = NK[5], c2;
        for (c2 = 5; c2 < 9; c2++) {
            K1t[c2] = NK[c2 + 1];
        }
        K1t[c2] = t2;

        System.out.println("\n\nAfter LS1: ");
        printArray(K1t);

        // 3. Apply P8
        for (int i = 0; i < 8; i++) {
            K1[i] = K1t[P8[i]];
        }

        System.out.println("\n\nAfter P8 - K1: ");
        printArray(K1);

        // 4. Apply LS2
        int p0 = K1t[0], p1 = K1t[1], y;
        for (y = 0; y < 3; y++) {
            K2t[y] = K1t[y + 2];
        }
        K2t[y++] = p0;
        K2t[y] = p1;

        int p5 = K1t[5], p6 = K1t[6], z;
        for (z = 5; z < 8; z++) {
            K2t[z] = K1t[z + 2];
        }
        K2t[z++] = p5;
        K2t[z] = p6;

        System.out.println("\n\nAfter LS2: ");
        printArray(K2t);

        // 5. Apply P8
        for (int i = 0; i < 8; i++) {
            K2[i] = K2t[P8[i]];
        }

        System.out.println("\n\nAfter P8 - K2:");
        printArray(K2);

    }

    public void encrypt() {

        // 1. Initial Permutation
        afterIP = applyIP(P);

        // 2. Expansion Permutation
        afterEP = applyEP(afterIP);

        // 3. XOR with K1
        afterXOR = applyXOR(afterEP, K1, 8);

        // 4. S-Box
        afterSBOX = applySBox(afterXOR);

        // 5. P4	
        afterP4 = applyP4(afterSBOX);

        // 6. XOR with LHS of afterIP
        afterXOR2 = applyXOR(afterP4, afterIP, 4);

        // 7. before swap LHS and RHS of afterIP
        System.arraycopy(afterXOR2, 0, newAfterIP, 0, 4);
        System.arraycopy(afterIP, 4, newAfterIP, 4, 4);

        System.out.println("\n\nBefore swap LHS & RHS of afterIP: ");
        printArray(newAfterIP);

        // 8. swap
        for (int p = 0; p < 4; p++) {
            newAfterIP[p] = afterIP[p + 4];
        }
        for (int p = 4; p < 8; p++) {
            newAfterIP[p] = afterXOR2[p - 4];
        }

        System.out.println("\n\nAfter swap: ");
        printArray(newAfterIP);

        // 9. EP on RHS
        afterEP = applyEP(newAfterIP);

        // 10. XOR with K2
        afterXOR = applyXOR(afterEP, K2, 8);

        // 11. S-Box
        afterSBOX = applySBox(afterXOR);

        // 12. P4	
        afterP4 = applyP4(afterSBOX);

        // 13. XOR with LHS of afterIP
        afterXOR2 = applyXOR(afterP4, newAfterIP, 4);

        // 14. before swap
        System.arraycopy(afterXOR2, 0, newAfterIP2, 0, 4);
        System.arraycopy(newAfterIP, 4, newAfterIP2, 4, 4);

        System.out.println("\n\nNew After_IP: ");
        printArray(newAfterIP2);

        // 15. IP inverse
        afterIP_Inv = applyIPInverse(newAfterIP2);

        C = afterIP_Inv;
        System.out.println("\n\nENCRYPTED CIPHER MESSAGE: ");
        printArray(C);

    }

    public void decrypt() {

        // 1. Initial Permutation
        afterIP = applyIP(C);

        // 2. Expansion Permutation
        afterEP = applyEP(afterIP);

        // 3. XOR with K1
        afterXOR = applyXOR(afterEP, K2, 8);

        // 4. S-Box
        afterSBOX = applySBox(afterXOR);

        // 5. P4	
        afterP4 = applyP4(afterSBOX);

        // 6. XOR with LHS of afterIP
        afterXOR2 = applyXOR(afterP4, afterIP, 4);

        // 7. before swap LHS and RHS of afterIP
        System.arraycopy(afterXOR2, 0, newAfterIP, 0, 4);
        System.arraycopy(afterIP, 4, newAfterIP, 4, 4);

        System.out.println("\n\nBefore swap: ");
        printArray(newAfterIP);

        // 8. swap
        for (int p = 0; p < 4; p++) {
            newAfterIP[p] = afterIP[p + 4];
        }
        for (int p = 4; p < 8; p++) {
            newAfterIP[p] = afterXOR2[p - 4];
        }

        System.out.println("\n\nAfter swap: ");
        printArray(newAfterIP);

        // 9. EP on RHS
        afterEP = applyEP(newAfterIP);

        // 10. XOR with K2
        afterXOR = applyXOR(afterEP, K1, 8);

        // 11. S-Box
        afterSBOX = applySBox(afterXOR);

        // 12. P4	
        afterP4 = applyP4(afterSBOX);

        // 13. XOR with LHS of afterIP
        afterXOR2 = applyXOR(afterP4, newAfterIP, 4);

        // 14. before swap
        System.arraycopy(afterXOR2, 0, newAfterIP2, 0, 4);
        System.arraycopy(newAfterIP, 4, newAfterIP2, 4, 4);

        System.out.println("\n\nNew After_IP");
        printArray(newAfterIP2);

        // 15. IP inverse
        afterIP_Inv = applyIPInverse(newAfterIP2);

//        C = afterIP_Inv;
        System.out.println("\n\nDECRYPTED PLAIN MESSAGE: ");
        printArray(afterIP_Inv);

    }

    public int[] applyIP(int[] arr) {

        int[] IP = {1, 5, 2, 0, 3, 7, 4, 6};

        int[] afterApplyingIP = new int[8];

        for (int c = 0; c < 8; c++) {
            afterApplyingIP[c] = arr[IP[c]];
        }

        System.out.println("\n\nAfter Initial Permutation: ");
        printArray(afterApplyingIP);

        return afterApplyingIP;
    }

    public int[] applyEP(int[] arr) {

        int[] EP = {3, 0, 1, 2, 1, 2, 3, 0};

        int[] afterApplyingEP = new int[8];

        for (int m = 0; m < 8; m++) {
            afterApplyingEP[m] = arr[EP[m] + 4];
        }

        System.out.println("\n\nAfter Expansion Permutation: ");
        printArray(afterApplyingEP);

        return afterApplyingEP;
    }

    public int[] applyXOR(int[] arr, int[] k, int len) {

        int[] afterApplyingXOR = new int[len];

        for (int g = 0; g < len; g++) {
            afterApplyingXOR[g] = arr[g] ^ k[g];
        }

        System.out.println("\n\nAfter XOR: ");
        printArray(afterApplyingXOR);

        return afterApplyingXOR;

    }

    public int[] applySBox(int[] arr) {

        int[][] S0 = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
        int[][] S1 = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

        int r1, c1, p1, r2, c2, p2;
        int afterApplyingSBox[] = new int[4];

        r1 = arr[0] * 2 + arr[3];
        c1 = arr[1] * 2 + arr[2];

        r2 = arr[4] * 2 + arr[7];
        c2 = arr[5] * 2 + arr[6];

        p1 = S0[r1][c1];
        p2 = S1[r2][c2];

        afterApplyingSBox[0] = p1 / 2;
        afterApplyingSBox[1] = p1 % 2;
        afterApplyingSBox[2] = p2 / 2;
        afterApplyingSBox[3] = p2 % 2;

        System.out.println("\n\nAfter reducing to 4 bits (s-box): ");
        printArray(afterApplyingSBox);

        return afterApplyingSBox;
    }

    public int[] applyP4(int[] arr) {

        int[] P4 = {1, 3, 2, 0};

        int[] afterApplyingP4 = new int[4];

        for (int q = 0; q < 4; q++) {
            afterApplyingP4[q] = arr[P4[q]];
        }

        System.out.println("\n\nAfter P4: ");
        printArray(afterApplyingP4);

        return afterApplyingP4;
    }

    public int[] applyIPInverse(int[] arr) {

        int[] IPinv = {3, 0, 2, 4, 6, 1, 7, 5};

        int[] afterApplyingIPInverse = new int[8];
        for (int c = 0; c < 8; c++) {
            afterApplyingIPInverse[c] = arr[IPinv[c]];
        }

        System.out.println("\n\nAfter Initial Permutation INVERSE: ");
        printArray(afterApplyingIPInverse);

        return afterApplyingIPInverse;
    }

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print("  " + a[i]);
        }
    }

    public static void main(String[] args) {
        sDES obj = new sDES();

        System.out.println("GIVEN PLAIN TEXT:");
        obj.printArray(obj.P);

        System.out.println("\n\n\n> FINDING KEYS K1 & K2");
        obj.keys();

        System.out.println("\n\n\n> ENCRYPTION");
        obj.encrypt();

        System.out.println("\n\n\n> DECRYPTION");
        obj.decrypt();

        System.out.println("\n\n\n");

    }

}

/*

 run:
 GIVEN PLAIN TEXT:
 1  0  1  0  0  1  0  1


 > FINDING KEYS K1 & K2


 After P10: 
 1  0  0  0  0  1  0  1  1  1

 After LS1: 
 0  0  0  0  1  0  1  1  1  1

 After P8 - K1: 
 0  0  1  0  1  1  1  1

 After LS2: 
 0  0  1  0  0  1  1  1  0  1

 After P8 - K2:
 1  1  1  0  1  0  1  0


 > ENCRYPTION


 After Initial Permutation: 
 0  1  1  1  0  1  0  0

 After Expansion Permutation: 
 0  0  1  0  1  0  0  0

 After XOR: 
 0  0  0  0  0  1  1  1

 After reducing to 4 bits (s-box): 
 0  1  1  1

 After P4: 
 1  1  1  0

 After XOR: 
 1  0  0  1

 Before swap LHS & RHS of afterIP: 
 1  0  0  1  0  1  0  0

 After swap: 
 0  1  0  0  1  0  0  1

 After Expansion Permutation: 
 1  1  0  0  0  0  1  1

 After XOR: 
 0  0  1  0  1  0  0  1

 After reducing to 4 bits (s-box): 
 0  0  1  0

 After P4: 
 0  0  1  0

 After XOR: 
 0  1  1  0

 New After_IP: 
 0  1  1  0  1  0  0  1

 After Initial Permutation INVERSE: 
 0  0  1  1  0  1  1  0

 ENCRYPTED CIPHER MESSAGE: 
 0  0  1  1  0  1  1  0


 > DECRYPTION


 After Initial Permutation: 
 0  1  1  0  1  0  0  1

 After Expansion Permutation: 
 1  1  0  0  0  0  1  1

 After XOR: 
 0  0  1  0  1  0  0  1

 After reducing to 4 bits (s-box): 
 0  0  1  0

 After P4: 
 0  0  1  0

 After XOR: 
 0  1  0  0

 Before swap: 
 0  1  0  0  1  0  0  1

 After swap: 
 1  0  0  1  0  1  0  0

 After Expansion Permutation: 
 0  0  1  0  1  0  0  0

 After XOR: 
 0  0  0  0  0  1  1  1

 After reducing to 4 bits (s-box): 
 0  1  1  1

 After P4: 
 1  1  1  0

 After XOR: 
 0  1  1  1

 New After_IP
 0  1  1  1  0  1  0  0

 After Initial Permutation INVERSE: 
 1  0  1  0  0  1  0  1

 DECRYPTED PLAIN MESSAGE: 
 1  0  1  0  0  1  0  1



 BUILD SUCCESSFUL (total time: 0 seconds)



 */

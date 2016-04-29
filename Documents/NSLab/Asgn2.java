import java.util.Scanner;

public class Asgn2 {

	String plainText = "";
	int keyLength;
	int[] key;

	public String encrypt(String cc) {

		char c, n;
		String newText = "";

		int ctr = 0;

		for (int i = 0; i < cc.length(); i++) {
			c = cc.charAt(i);

			n = (char) (c + key[ctr]);
			ctr++;
			if (ctr >= keyLength)
				ctr = 0;

			newText += n;
			System.out.println("new string = " + newText);
		}

		return newText;

	}
	
	public String decrypt (String cc) {
		
		char c, n;
		String newText = "";

		int ctr = 0;

		for (int i = 0; i < cc.length(); i++) {
			c = cc.charAt(i);

			n = (char) (c - key[ctr]);
//			n = (char) (c + 26 - key[ctr]);
//			System.out.println("new  = " + n);
			ctr++;
			if (ctr >= keyLength)
				ctr = 0;

			newText += n;
			System.out.println("new string = " + newText);
		}

		return newText;
	}

	public static void main(String[] args) {

		Asgn2 obj = new Asgn2();

		@SuppressWarnings("resource")
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter plain text: ");
		obj.plainText = scanner.next();

		System.out.println("Enter key length: ");
		obj.keyLength = Integer.parseInt(scanner.next());
		obj.key = new int[obj.keyLength];

		for (int h = 0; h < obj.keyLength; h++) {
			System.out.println("Enter key array element" + h + ": ");
			obj.key[h] = Integer.parseInt(scanner.next());
		}

		String cipherText = obj.encrypt(obj.plainText);
		System.out.println("Vegenery Ciphered Text = " + cipherText);
		
		String decrypted = obj.decrypt(cipherText);
		System.out.println("Vegenery Ciphered Text = " + decrypted);

	}

}


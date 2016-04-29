

#include<stdio.h>
#include<math.h>
#include<string.h>

//Declaration
int key[3][16];
int w[6][8];
int Cipher_txt[16];


int plain_txt[16]={1,1,0,1,0,1,1,1,0,0,1,0,1,0,0,0};
int mainkey[16]={0,1,0,0,1,0,1,0,1,1,1,1,0,1,0,1};

int RoundConstant1[8]   ={1,0,0,0,0,0,0,0};
int RoundConstant2[8]   ={0,0,1,1,0,0,0,0};

int EncMatrix[2][2] = {{1,4},{4,1}};
int DecMatrix[2][2] = {{9,2},{2,9}};

int SBOX_Enc[4][4][4]={
{{1,0,0,1},{0,1,0,0},{1,0,1,0},{1,0,1,1},},
{{1,1,0,1},{0,0,0,1},{1,0,0,0},{0,1,0,1},},
{{0,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,1},},
{{1,1,0,0},{1,1,1,0},{1,1,1,1},{0,1,1,1},},
};


int SBOX_Dec[4][4][4]={
{{1,0,1,0},{0,1,0,1},{1,0,0,1},{1,0,1,1},},
{{0,0,0,1},{0,1,1,1},{1,0,0,0},{1,1,1,1},},
{{0,1,1,0},{0,0,0,0},{0,0,1,0},{0,0,1,1},},
{{1,1,0,0},{0,1,0,0},{1,1,0,1},{1,1,1,0},},
};


//Accepting input text………………
void accept()
{
        int i;
        printf("\nEnter plain_txt-\n");
        for(i=0;i<16;i++)
                scanf("%d",&plain_txt[i]);

        printf("\nEnter Key-\n");
        for(i=0;i<16;i++)
                scanf("%d",&mainkey[i]);
}


//For ddisplaying…………………….
void display(char *str,int *a,int size)
{
        int i;
        puts(str);
        for(i=0;i<size;i++)
        {
                printf("%d  ",a[i]);
        }
        printf("\n\n");
}


void AddRoundKey(int *a,int *b,int *k)
{
        int i;
        for(i=0;i<16;i++)
                b[i] = a[i] ^ k[i];
}



//function to XOR
void XOR(int *a,int *b,int size,int *output)
{
        int i;
        for(i=0;i<size;i++)
        {
                output[i] = a[i] ^ b[i];
        }
}
//------------------------------------------------------


void RotateNibble(int *a,int size,int *output)
{
        int i;
        for(i=0;i< (size/2) ;i++)
        {
                output[i] = a[i+4];
                output[i+4] = a[i];
        }
}




//------------------------------------------------------

void SubstituteNibble(int *a,int size,int *output)
{
        int i;
        for(i=0;i<4;i++)
        {
                output[i]  = SBOX_Enc[a[0]<<1|a[1]] [a[2]<<1|a[3]] [i];
                output[i+4]= SBOX_Enc[a[4]<<1|a[5]] [a[6]<<1|a[7]] [i];
                if(size > 8)
                {
                        output[i+8]  = SBOX_Enc[a[8]<<1|a[9]] [a[10]<<1|a[11]] [i];
                        output[i+12] = SBOX_Enc[a[12]<<1|a[13]] [a[14]<<1|a[15]] [i];
                }
        }
}


//------------------------------------------------------
void InverseSubstituteNibble(int *a,int size,int *output)
{
        int i;
        for(i=0;i<4;i++)
        {
                output[i]  = SBOX_Dec[a[0]<<1|a[1]] [a[2]<<1|a[3]] [i];
                output[i+4]= SBOX_Dec[a[4]<<1|a[5]] [a[6]<<1|a[7]] [i];
                if(size > 8)
                {
                        output[i+8]  = SBOX_Dec[a[8]<<1|a[9]] [a[10]<<1|a[11]] [i];
                        output[i+12] = SBOX_Dec[a[12]<<1|a[13]] [a[14]<<1|a[15]] [i];
                }
        }
}
//-------------------------------------------------------------------
void ShiftRow(int *a)
{
        int i,temp;
        for(i=0;i<4;i++)
        {
                temp   =a[i+4];
                a[i+4] =a[i+12];
                a[i+12]=temp;
        }
}


//------------------------------------------------------

void MixColumn(int *input,int MultiplicationMatrix[2][2],int *output)
{
        int matrix[2][2],a,b,c,d;
        getMatrixColumnWise(input,matrix);

        a = divide_binary(multiply_binary(MultiplicationMatrix[0][0],matrix[0][0]),19) ^ divide_binary(multiply_binary(MultiplicationMatrix[0][1],matrix[1][0]),19);
        c = divide_binary(multiply_binary(MultiplicationMatrix[0][0],matrix[0][1]),19) ^ divide_binary(multiply_binary(MultiplicationMatrix[0][1],matrix[1][1]),19);
        b = divide_binary(multiply_binary(MultiplicationMatrix[1][0],matrix[0][0]),19) ^ divide_binary(multiply_binary(MultiplicationMatrix[1][1],matrix[1][0]),19);
        d = divide_binary(multiply_binary(MultiplicationMatrix[1][0],matrix[0][1]),19) ^ divide_binary(multiply_binary(MultiplicationMatrix[1][1],matrix[1][1]),19);

        output[0] = a>>3 & 1;
        output[1] = a>>2 & 1;
        output[2] = a>>1 & 1;
        output[3] = a    & 1;

        output[4] = b>>3 & 1;
        output[5] = b>>2 & 1;
        output[6] = b>>1 & 1;
        output[7] = b    & 1;

        output[8]  = c>>3 & 1;
        output[9]  = c>>2 & 1;
        output[10] = c>>1 & 1;
        output[11] = c    & 1;

        output[12] = d>>3 & 1;
        output[13] = d>>2 & 1;
        output[14] = d>>1 & 1;
        output[15] = d    & 1;
}

//------------------------------------------------------

void generateKey()
{
        int j;
        for(j=0;j<8;j++)
        {
                w[0][j] = mainkey[j];
                w[1][j] = mainkey[j+8];
        }

        int input[8],output[8];

        RotateNibble(w[1],8,input);
        SubstituteNibble(input,8,output);
        XOR(RoundConstant1,output,8,output);
        XOR(w[0],output,8,w[2]);
        XOR(w[1],w[2],8,w[3]);

        RotateNibble(w[3],8,input);
        SubstituteNibble(input,8,output);
        XOR(RoundConstant2,output,8,output);
        XOR(w[2],output,8,w[4]);
        XOR(w[3],w[4],8,w[5]);

        for(j=0;j<8;j++)
        {
                key[0][j] = w[0][j];
                key[1][j] = w[2][j];
                key[2][j] = w[4][j];

                key[0][j+8] = w[1][j];
                key[1][j+8] = w[3][j];
                key[2][j+8] = w[5][j];
        }
        display("Key1:",key[0],16);
        display("Key2:",key[1],16);
        display("Key3:",key[2],16);
}

//------------------------------------------------------


void getMatrixColumnWise(int *a,int output[2][2])
{
        output[0][0] = a[0]<<3|a[1]<<2|a[2]<<1|a[3];
        output[1][0] = a[4]<<3|a[5]<<2|a[6]<<1|a[7];
        output[0][1] = a[8]<<3|a[9]<<2|a[10]<<1|a[11];
        output[1][1] = a[12]<<3|a[13]<<2|a[14]<<1|a[15];
}

//------------------------------------------------------


int multiply_binary(int a,int b)
{
        int i,multiplication=0;
        for(i=7;i>=0;i--)
        {
                if(b & 1<<i)
                {
                        multiplication ^= (a << i);
                }
        }
        return multiplication;
}

//------------------------------------------------------

int divide_binary(int a,int b)
{
        int i,remainder=a;
        double integral1,integral2;

        modf(log(remainder)/log(2),&integral1);
        modf(log(b)/log(2),&integral2);
        i = (int)integral1 - (int)integral2;
        while(i >= 0)
        {
                remainder ^= (b << (int)i);
                modf(log(remainder)/log(2),&integral1);
                modf(log(b)/log(2),&integral2);
                i = (int)integral1 - (int)integral2;
        }
        return remainder;
}
//------------------------------------------------------
void encryption()
{
        int i,temp[16],output_1[16],output_2[16];

        printf("Encryption:");
        AddRoundKey(plain_txt,temp,key[0]);
        display("After Add Round Key0",temp,16);

        printf("Round 1:");
        SubstituteNibble(temp,16,output_1);
        display("After Substitution of Nibble",output_1,16);
        ShiftRow(output_1);
        display("After Shift Row:",output_1,16);
        MixColumn(output_1,EncMatrix,output_1);
        display("After Mix Column:",output_1,16);
        AddRoundKey(output_1,output_1,key[1]);
        display("After Add Round Key1:",output_1,16);

        printf("Round 2:");
        SubstituteNibble(output_1,16,output_2);
        display("After Substitution of Nibble",output_2,16);
        ShiftRow(output_2);
        display("After Shift Row:",output_2,16);
        AddRoundKey(output_2,Cipher_txt,key[2]);
        display("Cipher text:",Cipher_txt,16);
}
//------------------------------------------------------
void decryption()
{
        int i,temp[16],output_1[16],output_2[16];

        printf("Decryption :");

        printf("Round 1:");
        AddRoundKey(Cipher_txt,temp,key[2]);
        display("After Add Round Key2:",temp,16);
        ShiftRow(temp);
        display("After Shift Row:",temp,16);
        InverseSubstituteNibble(temp,16,output_1);
        display("After Inverse Nibble Substitution:",output_1,16);

        printf("Round 2:");
        AddRoundKey(output_1,output_1,key[1]);
        display("After Add Round Key1:",output_1,16);
        MixColumn(output_1,DecMatrix,output_1);
        display("After Inverse Mix Column:",output_1,16);
        ShiftRow(output_1);
        display("After Inverse Shift Row:",output_1,16);
        InverseSubstituteNibble(output_1,16,output_2);
        display("After Inverse Nibble Substitution:",output_2,16);

        AddRoundKey(output_2,output_2,key[0]);
        display("Decrypted text:",output_2,16);
}

//------------------------------------------------------


int main()
{
        accept();
        generateKey();
        encryption();
        decryption();
        getch();
        return 0;
}

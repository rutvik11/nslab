#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int enc_matrix[3],matrix[3][3];
int sum=0;
int mod_m[3];
int main()
{
	int i,j,k;
	char msg[3];
	int message[3];
	printf("Enter the the value of mtrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
		//printf(" ans %d",matrix[i][j]);
	}
	
	printf("Enter the message\n");
	for(i=0;i<3;i++)
	{
		scanf("%s",&msg[i]);
	}
	for(i=0;i<3;i++)
	{
		message[i]=(int)msg[i]-97;
		
	}
	
	printf("The entered matrix is\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("The converted message is\n");
	for(i=0;i<3;i++)
	{
		printf("%d",message[i]);
		printf("\t");
	}
	
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				sum=sum+(message[k]*matrix[k][j]);
			}
		
		enc_matrix[j]=sum;
		
		sum=0;
		}
	
	
	for(i=0;i<3;i++)
	{
		if(enc_matrix[i]%26<0)
		{
			enc_matrix[i]=(enc_matrix[i]%26)+26;
		}
		else
		{
			enc_matrix[i]=(enc_matrix[i]%26);
		}
	}
	printf("Final cipher is ");
	
	for(i=0;i<3;i++)
	{
		mod_m[i]=enc_matrix[i]+97;
	}
	for(i=0;i<3;i++)
	{
		printf("%c",(char)mod_m[i]);
	}
	dec();
}

int dec()
{
	int det=0;
	int inv[3][3],i,j,k,dec_matrix[3],dmod_m[3];
	for(i=0;i<3;i++)
	{
		det=det+(matrix[0][i]*(matrix[1][(i+1)%3]*matrix[2][(i+2)%3]-matrix[1][(i+2)%3]*matrix[2][(i+1)%3]));
	}
	if(det==0)
	{
		printf("\nInverse cannot exist\n");
	}
	else
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
			inv[i][j]=((matrix[(i+1)%3][(j+1)%3]*matrix[(i+2)%3][(j+2)%3])-(matrix[(i+1)%3][(j+2)%3]*matrix[(i+2)%3][(j+1)%3]))/det;	
			}
		}
		printf("Inverted matrix is\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d\t",inv[i][j]);
			}
			printf("\n");		
		}

		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				sum=sum+(enc_matrix[k]*inv[k][j]);
			}
		
		dec_matrix[j]=sum;
		
		sum=0;
		}

		for(i=0;i<3;i++)
		{
		if(dec_matrix[i]%26<0)
		{
			dec_matrix[i]=(dec_matrix[i]%26)+26;
		}
		else
		{
			dec_matrix[i]=(dec_matrix[i]%26);
		}
	}
	printf("Decrypted cipher is ");
	
	for(i=0;i<3;i++)
	{
		dmod_m[i]=dec_matrix[i]+97;
	}
	for(i=0;i<3;i++)
	{
		printf("%c",(char)dmod_m[i]);
	}
	}
}

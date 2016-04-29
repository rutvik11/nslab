#include<stdio.h>

int main()
{
int i=0,a[3][3],inverse[3][3];
float determinant;

printf("\nENTER THE MATRIX :");

for(i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
scanf("%d",&a[i][j]);
}
}

  for(i=0;i<3;i++)
      determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

printf("\n%f",determinant);
 
   printf("\nInverse of matrix is: \n\n");
   for(i=0;i<3;i++){
      for(int j=0;j<3;j++)
           printf("%.2f\t",((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant);
       printf("\n");
   }
return 0;
}


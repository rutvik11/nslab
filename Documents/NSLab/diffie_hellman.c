#include<stdio.h>
#include<math.h>
int x_a,x_b,p,a,y_a,y_b;

long long int power(int a,int b,int mod)
{
 long long int t;
 if(b==1)
  return a;
 t=power(a,b/2,mod);
 if(b%2==0)
  return (t*t)%mod;
 else
  return (((t*t)%mod)*a)%mod;
} 
void main(){

printf("\n\n\tENTER THE PRIVATE KEYS OF A AND B : ");
scanf("%d%d",&x_a,&x_b);

printf("\n\n\tENTER THE PRIME AND ITS PRIMITIVE ROOT : ");
scanf("%d%d",&p,&a);

y_a = power(a,x_a,p);
printf("\n\n\t VALUE OF y_a : %d",y_a);

y_b=power(a,x_b,p);
printf("\n\n\t VALUE OF y_b : %d",y_b);


printf("\n\n\t PUBLIC KEY OF A : %lld",power(y_b,x_a,p));
printf("\n\n\t PUBLIC KEY OF B : %lld",power(y_a,x_b,p));

}

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long int p,q,e,n,phi_n,d;
int flag =0,v_e[10],v_d[10];

unsigned long int ipow( int base, long int exp )
{
    unsigned long int result = 1;
    while( exp )
    {
	result = result*base;
	exp--;
    }
    return result;
}
int check_prime( int pr)
{
int i,j;
 
j=sqrt(pr);
 
for (i=2;i<=j;i++) {
 
if(pr%i==0)
 
return 0;
 
}
 
return 1;
}

int calculate_d(int el)
{
int dl=0,i=1;
while(i)
{
dl=i;
if(((dl*el)%phi_n) == 1)
{
dl=i;
i=0;
}
else
i++;
}
return dl;
}

void calculate_e()
{
int i=0,k=0;
for (i=2;i<phi_n;i++)
{
if(phi_n % i == 0)
continue;

flag = check_prime(i);
if(flag == 1 && i!=p && i!=q)
{
v_e[k] = i;
v_d[k] = calculate_d(v_e[k]);

}
}
}
void main(){
long int p,q,e,n,phi_n,d;
int m,c,i=1;

printf("\n\n\tENTER THE VALUE OF p AND q : ");
scanf("%ld%ld",&p,&q);

printf("\n\n\tENTER THE VALUE OF e : ");
scanf("%ld",&e);

printf("\n\n\tENTER THE VALUE OF m : ");
scanf("%d",&m);

n = p*q;
phi_n = (p-1)*(q-1);



while(i)
{
d=i;
if(((d*e)%phi_n) == 1)
{
d=i;
i=0;
}
else
i++;
}
 

printf("\n\n\t PUBLIC KEY : (%ld,%ld)",e,n);
printf("\n\n\t PRIVATE KEY : (%ld,%ld)",d,n);

c = ((ipow(m,e)) % n);
printf("\n\n\tENCRYPTED DATA IS : %d",c);

m = ((ipow(c,d)) % n);
printf("\n\n\tDECRYPTED DATA IS : %d",m);

calculate_e();

printf("\n\n\tPOSSIBLE VALUES OF e AND d ARE :\n\n\t\t\t");
for(i=0;i<10;i++)
{
printf("%d\t%d\n\t\t\t",v_e[i],v_d[i]);
}

}


#include<stdio.h>
#include<math.h>

int i,j,y_P,x_p,x_q,y_p,y_q,x_r,y_r,p,a,b,lambda,t,x,y,na,nb,pa_x,pb_x,pa_y,pb_y,x_g,y_g,ka_x,ka_y,kb_x,kb_y;
int temp;

int modInverse(int denominator, int modulus) {

		int mmi, e, mod;

		mod = denominator % modulus;
		mod = mod % modulus;

		if (mod < 0) 
			mod += modulus;

		for (e = 1; e <= modulus; e++) {
			if (((mod * e) % modulus) == 1) {
				break;
			}
		}

		mmi = e;
		
		return mmi;
}

void add_same()
{
temp = (3*(pow(x_p,2)) + 9);
temp = temp % p;
lambda=( temp *modInverse(2*y_p,p)) %p;
//lambda = modInverse(temp,p);
printf("%d",lambda);

x_r = (pow(lambda,2)-x_p-y_p);
x_r = x_r%p;
while(x_r<=0)
    {
        x_r=x_r+p;
    }

y_r = (lambda*(x_p - x_r)- y_p) % p;

while(y_r<=0)
    {
        y_r=y_r+p;
    }
printf("\n\n\tResultant x = %d\n\tResultant Y = %d",x_r,y_r);
}

void add_different()
{
temp=(((y_q-y_p)%p)*modInverse(x_q-x_p,p))%p;
lambda = temp;//modInverse(temp,p);
x_r = (pow(lambda,2)-x_p-y_p);
x_r = x_r%p;
y_r = (lambda*(x_p - x_r)- y_p) % p;
printf("\n\n\tResultant x = %d\n\tResultant Y = %d",x_r,y_r);
}

void dhke()
{
printf("\n\n\tENTER THE VALUES OF Xg AND Yg : ");
scanf("%d%d",&x_g,&y_g);

na = rand()%10+2;
nb = rand()%10+2;

//public key of A

x_r = x_g;
y_r = y_g;

for(i=0;i<na-1;i++)
{
if(x_g == x_r && y_g == y_r)
{
temp = (3*(pow(x_g,2)) + 9);
temp = temp % p;
lambda=( temp *modInverse(2*y_g,p)) %p;
}
else
{
temp=(((y_r-y_g)%p)*modInverse(x_r-x_g,p))%p;
lambda = temp;//modInverse(temp,p);
}
x_r = (pow(lambda,2)-x_g-x_r);
x_r = x_r%p;
y_r = (lambda*(x_g - x_r)- y_g) % p;
}
pa_x = x_r;
pa_y = y_r;

//public key of B

x_r = x_g;
y_r = y_g;

for(i=0;i<nb-1;i++)
{
if(x_g == x_r && y_g == y_r)
{
temp = (3*(pow(x_g,2)) + 9);
temp = temp % p;
lambda=( temp *modInverse(2*y_g,p)) %p;
}
else
{
temp=(((y_r-y_g)%p)*modInverse(x_r-x_g,p))%p;
lambda = temp;//modInverse(temp,p);
}
x_r = (pow(lambda,2)-x_g-x_r);
x_r = x_r%p;
y_r = (lambda*(x_g - x_r)- y_g) % p;
}
pb_x = x_r;
pb_y = y_r;

//secret key of A
x_r = pb_x;
y_r = pb_y;

for(i=0;i<na;i++)
{
if(x_g == x_r && y_g == y_r)
{
temp = (3*(pow(x_g,2)) + 9);
temp = temp % p;
lambda=( temp *modInverse(2*y_g,p)) %p;
}
else
{
temp=(((y_r-y_g)%p)*modInverse(x_r-x_g,p))%p;
lambda = temp;//modInverse(temp,p);
}
x_r = (pow(lambda,2)-x_g-x_r);
x_r = x_r%p;
y_r = (lambda*(x_g - x_r)- y_g) % p;
}
ka_x = x_r;
ka_y = y_r;

//secret of b
x_r = pa_x;
y_r = pa_y;

for(i=0;i<nb;i++)
{
if(x_g == x_r && y_g == y_r)
{
temp = (3*(pow(x_g,2)) + 9);
temp = temp % p;
lambda=( temp *modInverse(2*y_g,p)) %p;
}
else
{
temp=(((y_r-y_g)%p)*modInverse(x_r-x_g,p))%p;
lambda = temp;//modInverse(temp,p);
}
x_r = (pow(lambda,2)-x_g-x_r);
x_r = x_r%p;
y_r = (lambda*(x_g - x_r)- y_g) % p;
}
kb_x = x_r;
kb_y = y_r;

if(ka_x == kb_x && ka_y == kb_y)
{
printf("\n\n\tSUCESS EXCHANGE");
}
else
{
printf("\n\n\tWRONG EXCHANGE");
}
}
void main()
{
int choice;
int rhs,lhs;
        printf("\n\n\tENTER THE VALUES OF a AND b : ");
        scanf("%d%d",&a,&b);
        printf("\n\n\tENTER THE PRIME NUMBER : ");
        scanf("%d",&p);
     

printf("\n\n\t1.CHECK\n\t2.ADD SAME\n\t3.ADD DIFFERENT\n\tENTER YOUR CHOICE : ");
scanf("%d",&choice);

switch(choice)
{
case 1: printf("\n\n\tENTER THE VALUES OF x AND y : ");
        scanf("%d%d",&x,&y);

        lhs = pow(y,2);
        lhs = lhs%p;
        rhs = (pow(x,3)+(a*x)+b);
        rhs = rhs%p;
      
        if(lhs == rhs)
        { printf("\n\n\tPOINTS BELONGS TO THE EQUATION..."); }
        else
         {printf("\n\n\tPOINTS DOES NOT BELONGS TO THE EQUATION..."); } 
         break;

case 2: printf("\n\n\tENTER THE VALUES OF x AND y : ");
        scanf("%d%d",&x,&y);

        add_same();
        break;

case 3: printf("\n\n\tENTER THE VALUES OF x AND y : ");
        scanf("%d%d",&x,&y);

         add_different();
         break;

case 4: dhke();
        break;
default: printf("\n\n\tWRONG INPUT TRY AGAIN.....");  
         break;
}


}

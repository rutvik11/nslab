#include<stdio.h>
#include<math.h>

int a, b, p, na, nb, lambda, temp, n;
int pax, pay, pbx, pby;
int xp, yp, xq, yq, xr, yr;
    
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

void publickey(int n)
{
    xq = xp;
    yq = yp;
    
    for(int i = 0; i<n-1; i++)
    {
        if(xp == xq && yp == yq)
        {
           temp = (3*pow(xp,2)) + a;   
           temp = temp%p;
           lambda = (temp*modInverse(2*yp,p))%p;
        }
        else
        {
            temp = (((yq-yp)%p)*modInverse(xq-xp,p))%p;
            lambda = temp;
        }
        
        xr = (pow(lambda,2)-xp-xq);
        xr = xr%p;
        yr = (lambda*(xp-xr)-yp)%p;
        
        if(xr<0)
        {
            xr=p+xr;
        }
        if(yr<0)
        {
            yr=p+yr;
        }
        
        xq = xr;
        yq = yr;

     }
    
}

void secretkey(int xp, int yp, int n)
{
    xq = xp;
    yq = yp;
    
    for(int i = 0; i<n-1; i++)
    {
        if(xp == xq && yp == yq)
        {
           temp = (3*pow(xp,2)) + a;   
           temp = temp%p;
           lambda = (temp*modInverse(2*yp,p))%p;
        }
        else
        {
            temp = (((yq-yp)%p)*modInverse(xq-xp,p))%p;
            lambda = temp;
        }
        
        xr = (pow(lambda,2)-xp-xq);
        xr = xr%p;
        yr = (lambda*(xp-xr)-yp)%p;
        
        if(xr<0)
        {
            xr=p+xr;
        }
        if(yr<0)
        {
            yr=p+yr;
        }
        
        xq = xr;
        yq = yr;
    }
}

int main()
{
    
    printf("\n\nEnter the values of a and b - ");
    scanf("%d%d",&a,&b);
    
    printf("\nEnter the prime number - ");
    scanf("%d",&p);
    
    
    printf("\nEnter the values of xp and yp - ");
    scanf("%d%d",&xp,&yp);
    
    na = rand()%10+2;
    printf("\nValue of Na - %d",na);
    nb = rand()%10+2;
    printf("\nValue of Nb - %d",nb);
    
    int public_key[4], private_key[4];
    publickey(na);
    public_key[0] = xq;
    public_key[1] = yq;
    
    printf("\nPublic key of A - (%d ,%d)\n\n",public_key[0],public_key[1]);
    
    publickey(nb);
    public_key[2] = xq;
    public_key[3] = yq;
    
    printf("Public key of B - (%d ,%d)\n\n",public_key[2],public_key[3]);
    
    secretkey(public_key[2], public_key[3], na);
    private_key[0] = xq;
    private_key[1] = yq;
    
    printf("\nShared Secret key of A - (%d ,%d)\n\n",private_key[0],private_key[1]);
    
    secretkey(public_key[0], public_key[1], nb);
    private_key[2] = xq;
    private_key[3] = yq;
    
    printf("\nShared Secret key of B - (%d ,%d)\n\n",private_key[2],private_key[3]);
    
    
    
    
    return 0;
    
}
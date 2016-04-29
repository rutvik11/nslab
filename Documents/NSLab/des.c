#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int key[10]={0,0,1,0,0,1,0,1,1,1};
int PT[8]={1,0,1,0,0,1,0,1};
int IP[8]={2,6,3,1,4,8,5,7};
int IIP[8]={4,1,3,5,7,2,8,6};
int EP[8]={4,1,2,3,2,3,4,1};
int p10[10]={3,5,2,7,4,10,1,9,8,6};
int p8[8]={6,3,7,4,8,5,10,9};
int p4[4]={2,4,3,1};
int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
int s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int key_p10[10],key_1[8],key_2[8],s0s1[4];
int main()
{
	key_gen();
	encrypton();
}
int encrypton()
{
	printf("Encryption\n");
	int ip_enc[8],L[4],R[4],ep_enc[8],i,sb_0[4],sb_1[4],out_1[4];
	int rn_2[8];
	int row,col;
	for(i=0;i<8;i++)
		ip_enc[i]=PT[IP[i]-1];
	display("After IP",ip_enc,8);
	for(i=0;i<4;i++)
	{
		L[i]=ip_enc[i];
		R[i]=ip_enc[i+4];
	}
	for(i=0;i<8;i++)
		ep_enc[i]=R[EP[i]-1];
	display("After E/P",ep_enc,8);
	for(i=0;i<8;i++)
	{
		ep_enc[i]=key_1[i]^ep_enc[i];
	}
	display("After XOR",ep_enc,8);
	for(i=0;i<4;i++)
	{
		sb_0[i]=ep_enc[i];
		sb_1[i]=ep_enc[i+4];
	}
	row=cal(sb_0[0],sb_0[3]);
	col=cal(sb_0[1],sb_0[2]);
	int f,g;
	f=s0[row][col];
	row=cal(sb_1[0],sb_1[3]);
	col=cal(sb_1[1],sb_1[2]);
	g=s1[row][col];
	dec(f);
	decc(g);
	for(i=0;i<4;i++)
		out_1[i]=s0s1[p4[i]-1];
	display("After P4",out_1,4);
	for(i=0;i<4;i++)
	{
		out_1[i]=(out_1[i])^(L[i]);
	}
	display("After XOR",out_1,4);
	for(i=0;i<4;i++)
	{
		rn_2[i]=R[i];
		rn_2[i+4]=out_1[i];
	}
	display("After Round 2",rn_2,8);
	
	int ep_encc[8];


	for(i=0;i<4;i++)
	{
		L[i]=rn_2[i];
		R[i]=rn_2[i+4];
	}
	display("R",R,4);
	for(i=0;i<8;i++)
		ep_enc[i]=R[EP[i]-1];
	display("After E/P",ep_enc,8);
	for(i=0;i<8;i++)
	{
		ep_enc[i]=key_2[i]^ep_enc[i];
	}
	display("After XOR",ep_enc,8);
	for(i=0;i<4;i++)
	{
		sb_0[i]=ep_enc[i];
		sb_1[i]=ep_enc[i+4];
	}
	row=cal(sb_0[0],sb_0[3]);
	col=cal(sb_0[1],sb_0[2]);
	
	f=s0[row][col];
	row=cal(sb_1[0],sb_1[3]);
	col=cal(sb_1[1],sb_1[2]);
	g=s1[row][col];
	dec(f);
	decc(g);
	for(i=0;i<4;i++)
		out_1[i]=s0s1[p4[i]-1];
	display("After P4",out_1,4);
	for(i=0;i<4;i++)
	{
		out_1[i]=(out_1[i])^(L[i]);
	}
	display("After XOR",out_1,4);
	display("R",R,4);
	for(i=0;i<4;i++)
	{
		rn_2[i]=out_1[i];
		rn_2[i+4]=R[i];
	}
	display("Joining",rn_2,8);
	int cip[8];
	for(i=0;i<8;i++)
		cip[i]=rn_2[IIP[i]-1];
	display("Cipher text is",cip,8);
	
}
int cal(int a,int b)
{
	
	int out;
	if(a==0&&b==0)
	{
		 out=0;
	}
	if(a==0&&b==1)
	{
		 out=1;
	}	
	if(a==1&&b==0)
	{
		 out=2;
	}
	if(a==1&&b==1)
	{
		 out=3;
	}
	return out;
}
int dec(int out)
{
	if(out==0)
		{
			
			s0s1[0]=0;s0s1[1]=0;
		}
	else if(out==1)
		{
			s0s1[0]=0;s0s1[1]=1;
		}
	else if(out==2)
		{
			s0s1[0]=1;s0s1[1]=0;
			
		}
	else if(out==3)
		{
			s0s1[0]=1;s0s1[1]=1;
			
		}
		
}
int decc(int out)
{
	if(out==0)
		{
			
			s0s1[2]=0;s0s1[3]=0;
		}
	else if(out==1)
		{
			s0s1[2]=0;s0s1[3]=1;
		}
	else if(out==2)
		{
			s0s1[2]=1;s0s1[3]=0;
			
		}
	else if(out==3)
		{
			s0s1[2]=1;s0s1[3]=1;
			
		}
		
}
int key_gen()
{
	int i,out_1[10],out_2[8];
	for(i=0;i<10;i++)
	{
		key_p10[i]=key[p10[i]-1];
	}	
	display("After p10",key_p10,10);
	LS(key_p10,1,10,out_1);
	display("After LS_1",out_1,10);
	for(i=0;i<8;i++)
	{
		key_1[i]=out_1[p8[i]-1];
	}
	display("After p8 key 1",key_1,8);
	
	LS(out_1,2,10,out_2);
	display("After LS_2",out_2,10);
	for(i=0;i<8;i++)
	{
		key_2[i]=out_2[p8[i]-1];
	}
	display("After p8 key 2",key_2,8);	
}
int LS(int a[],int by,int mn,int s[mn])
{
	int index=0,i;
	for( i=by;index<mn/2;i++)
	{
		s[index++]=a[i%(mn/2)];
	}	

	for( i=by+(mn/2);index<mn;i++)
	{
		s[index++]=a[(mn/2)+i%(mn/2)];

	}


}

int display(char *c,int a[],int s)
{
	int i;
	printf("%s\n",c);
	for(i=0;i<s;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

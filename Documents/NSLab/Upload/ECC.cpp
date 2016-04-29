#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int P[2],Q[2],E[2],p;
int delta1,delta2;
int r1,r2,res1,res2,s1,s2;
int R[2];

int G[2],Ep[2],q,na,nb,binary[10],Gnext[2];int rem[10];
int* bin1;int* bin2;
//int arr[10][10];
int* temp;int* temp1;
int delta;

int* pa; int* pb;
int* k1; int* k2;

void accept_inputs(){

	cout<<"Enter the coordinates of P: ";
	cin>>P[0]>>P[1];

	cout<<"Enter the coordinates of Q: ";
	cin>>Q[0]>>Q[1];

	cout<<"Enter the coordinates of E: ";
	cin>>E[0]>>E[1];

	cout<<"Enter the value of p: ";
	cin>>p;

}


int multiplicative_inverse(int num,int p){

		 int temp;
		
		for(int m=0;m<p;m++){
			if((num*m)%p == 1){
				temp = m;
				break;
			}
		}

		 return temp;
}



int calculate_delta_equal(int M[],int N[],int p){

	s1 = 3*(M[0]*M[0])+N[0] ;
	s2 = (2*M[1]) ;

	cout<<"s1: "<<s1<<" s2: "<<s2;
	if(s2 > 0)
			res2 = multiplicative_inverse(s2,p);
	else{
			p = s2%p;
			res2 = p + s2;
			res2 = multiplicative_inverse(res2,p);
	}

	if(s1 > 0)
		res1 = s1 % p;
	else
		res1 = (p + s1) % p;

	delta1 = (res1*res2) % p;
	//cout<<"Delta for P=Q is:  "<<delta1;

	return delta1;
}

int calculate_delta_not_equal(int X[],int Y[],int p){

	r1 = (Y[1] - X[1]);
	r2 = (Y[0] - X[0]); 

	if(r2 > 0)
			res2 = multiplicative_inverse(r2,p);
	else{
		
			//p=r2%p;
			//res2 = p + r2;
			r2 = r2*(-1);
			res2 = r2%p;
			res2 = p - res2;
			res2 = multiplicative_inverse(res2,p);
	}

	if(r1 > 0)
		res1 = r1 % p;
	else{
		//res1 = (p + r1) % p;
		r1 = r1*(-1);
		res1 = r1%p;
		res1 = p - res1;
	}

	delta2 = (res1*res2) % p;
	//cout<<"Delta for P!=Q is:  "<<delta2;

	return delta2;

}

int* calculate_P_plus_Q(int S[],int T[],int p,int delta){
	
	int xr,yr;
	

	if(S[0]!=T[0] && S[1]!=T[1])									//P!=Q
	{
		xr = ((delta*delta) - S[0] - T[0]) % p;
		yr = (((-1)*S[1]) + delta * (S[0] - xr)) % p;
	}
	else															//P=Q
	{
		xr = ((delta*delta) - S[0] - T[0]) % p;		
		yr = (((-1)*S[1]) + delta* (S[0] - xr)) % p;
	}	

	if(xr < 0)
		xr = p + xr;
	
	if(yr < 0)
		yr = p + yr;
	

	R[0] = xr; R[1] = yr;
	cout<<endl<<" P+Q: "<<R[0] <<"  "<<R[1] ;

	return R;
}

void accept_inputs_DHKE(){

	cout<<"Enter nA and nB: ";
	cin>>na>>nb;

	cout<<"Enter coordinate of G: ";
	cin>>G[0]>>G[1];

	cout<<"Enter coordinate of Ep: ";
	cin>>Ep[0]>>Ep[1];

	cout<<"Enter the value of P: ";
	cin>>q;
}

int* convert_to_binary(int num1){
	
		
		int i=0;

		for(int i=0;i<10;i++){
			rem[i] = 0;
			binary[i] = 0;
		}
		while(num1 != 0){

				rem[i] = num1%2;
				num1 = num1/2;
				i++;
		}
		i--;
		int j=0;
		for(i=9;i>=0;i--){
			binary[j] = rem[i];
			j++;
		}
		cout<<"Binary of na: ";
		for(int i=0;i<10;i++)
			cout<<binary[i];



	return rem;
}

int* calculate_public_key(int* bin1,int n1){

					int k=1;
					int cnt=0;

					while(n1>k){
							k = k+k;
							cnt++;
					}
						
					cout<<endl<<"cnt is: "<<cnt;
					int arr[cnt][2];
					//cout<<"hello ";
					//calculate_delta_equal(G,Ep,q);
					arr[0][0] = G[0];
					arr[0][1] = G[1];
					for(int i=1;i<cnt;i++){
							delta = calculate_delta_equal(G,Ep,q);
							cout<<"G is: ";
							for(int a=0;a<2;a++)
								cout<<" "<< G[a];
							temp = calculate_P_plus_Q(G,G,q,delta);
							


							for(int j=0;j<2;j++){
									arr[i][j] = temp[j];
									G[j] = temp[j];
							}
					}
					
					cout<<endl<<"Array contains: ";
						for(int i=0;i<cnt;i++)
							for(int j=0;j<2;j++){
								 cout<<" "<<arr[i][j];
							}

					cout<<"bin1 in cpk: ";		
					for(int i=0;i<cnt;i++)
						cout<<bin1[i];
					
					int v=0;
					for(int i=0;i<cnt;i++){
							
						if(bin1[i]!=0){
								v++;
								if(v==1){
									G[0] = arr[i][0];
								    G[1] = arr[i][1];
								}
								else{
									Gnext[0] = arr[i][0];
								    Gnext[1] = arr[i][1];

								    cout<<"Gnext: ";
								    for(int j=0;j<2;j++)
								    	cout<<" "<<Gnext[j];
								}
								//cout<<endl<<"G is: "<<G[0]<<" "<<G[1];
								//cout<<endl<<"Gnext is: "<<Gnext[0]<<" "<<Gnext[1];
								//cout<<endl<<"p is: "<<q;
							if(Gnext[0]!=0){
								delta = calculate_delta_not_equal(G,Gnext,q);
								cout<<"delta is: "<<delta;
								temp1 = calculate_P_plus_Q(G,Gnext,q,delta);
								
								for(int j=0;j<2;j++){
										G[j] = temp1[j];
								}
							}
						}
					}
						
					cout<<endl<<"Final G: "	;
					for(int j=0;j<2;j++){
								 cout<<" "<<G[j];
							}
	

			return G;				
}

int main(){	

	//accept_inputs();
	//calculate_delta_equal();
	//calculate_delta_not_equal();
	//calculate_P_plus_Q();
	int n,z;
	
	cout<<"Option Menu:  ";
	
	do{

		cout<<"1.Calculation P=Q(2P) p+p "<<endl<<"2.Calculation P!=Q P+Q"<<endl<<"3.ECC Over DHKE ";
		cout<<endl<<"Enter your choice: ";
		cin>>n;

		switch(n){

			case 2:
					accept_inputs();
					delta = calculate_delta_not_equal(P,Q,p);
					calculate_P_plus_Q(P,Q,p,delta);
					break;
			case 1:
					accept_inputs();
					delta = calculate_delta_equal(P,E,p);
					calculate_P_plus_Q(P,P,p,delta);
					break;
			
			case 3: 
					accept_inputs_DHKE();									//accept_inputs_DHKE;
					bin1 = convert_to_binary(na);
					int G1[2];
					G1[0] = G[0];
					G1[1] = G[1];
					cout<<endl<<"Calculation for pa: ";
					pa  = calculate_public_key(bin1,na);
					cout<<endl<<"Pa is: ";
					for(int i=0;i<2;i++)
						cout<<" "<<pa[i];

					G[0] = pa[0]; Gnext[0] = 0;
					Gnext[1] =0;
					G[1] = pa[1];
					bin2 = convert_to_binary(nb);

					k2 = calculate_public_key(bin2,nb);

					cout<<endl<<"K2 is: ";
					for(int i=0;i<2;i++)
						cout<<" "<<k2[i];

					bin2 = convert_to_binary(nb);
					G[0] = G1[0]; Gnext[0] = 0;
					Gnext[1] =0;
					G[1] = G1[1];
					cout<<endl<<"Calculation for pb: ";
					pb = calculate_public_key(bin2,nb);

					cout<<endl<<"pb is: ";
					for(int i=0;i<2;i++)
						cout<<" "<<pb[i];

					G[0] = pb[0]; Gnext[0] = 0;
					Gnext[1] =0;
					G[1] = pb[1];
					bin1 = convert_to_binary(na);

					k1 = calculate_public_key(bin1,na);

					cout<<endl<<"K1 is: ";
					for(int i=0;i<2;i++)
						cout<<" "<<k1[i];



					


					//compare code

					cout<<endl<<"Compare K1 and K2: ";

					if(k1[0]==k2[0] && k1[1]==k2[1])
						cout<<endl<<"Keys are same........!";
					else
						cout<<endl<<"Keys are not matched..! ";

				/*	while(na>k){
							k = k+k;
							cnt++;
					}
						
					cout<<endl<<"cnt is: "<<cnt;
					
					cout<<"hello ";
					//calculate_delta_equal(G,Ep,q);
					for(int i=0;i<cnt-1;i++){
							calculate_delta_equal(G,Ep,q);
							cout<<"G is: ";
							for(int a=0;a<2;a++)
								cout<<" "<< G[a];
							temp = calculate_P_plus_Q(G,G,q);
							


							for(int j=0;j<2;j++){
									arr[i][j] = temp[j];
									G[j] = temp[j];
							}
					}*/
					//bin2 = convert_to_binary(nb);
					
					//calculate public key
					//cacluate keys
					//compare the keys
					break;
			
			default: exit(0);
					 break;
		}
		cout<<"Do you want to continue:(0/1)";
		cin>>z;

	}while(z!=0);
	
	
	cout<<endl;
	return 0;
}

/* 
Output:

akshay@akshay-pc:~$ g++ ECC.cpp
akshay@akshay-pc:~$ ./a.out
Option Menu:  1.Calculation P=Q(2P) p+p 
2.Calculation P!=Q P+Q
3.ECC Over DHKE 
Enter your choice: 1
Enter the coordinates of P: 2 2
Enter the coordinates of Q: 2 2
Enter the coordinates of E: 0 -4
Enter the value of p: 211
s1: 12 s2: 4
 P+Q: 5  200Do you want to continue:(0/1)1
1.Calculation P=Q(2P) p+p 
2.Calculation P!=Q P+Q
3.ECC Over DHKE 
Enter your choice: 2
Enter the coordinates of P: 3 10
Enter the coordinates of Q: 9 7
Enter the coordinates of E: 1 1
Enter the value of p: 23

 P+Q: 17  20Do you want to continue:(0/1)3
1.Calculation P=Q(2P) p+p 
2.Calculation P!=Q P+Q
3.ECC Over DHKE 
Enter your choice: 3
Enter nA and nB: 121 203
Enter coordinate of G: 2 2
Enter coordinate of Ep: 0 -4
Enter the value of P: 211
Binary of na: 0001111001
Calculation for pa: 
cnt is: 7s1: 12 s2: 4G is:  2 2
 P+Q: 5  200s1: 75 s2: 400G is:  5 200
 P+Q: 159  114s1: 75843 s2: 228G is:  159 114
 P+Q: 174  163s1: 90828 s2: 326G is:  174 163
 P+Q: 181  209s1: 98283 s2: 418G is:  181 209
 P+Q: 136  11s1: 55488 s2: 22G is:  136 11
 P+Q: 147  97
Array contains:  2 2 5 200 159 114 174 163 181 209 136 11 147 97bin1 in cpk: 1001111Gnext:  174 163delta is: 169
 P+Q: 111  145Gnext:  181 209delta is: 19
 P+Q: 69  20Gnext:  136 11delta is: 66
 P+Q: 142  15Gnext:  147 97delta is: 143
 P+Q: 115  48
Final G:  115 48
Pa is:  115 48Binary of na: 0011001011
cnt is: 8s1: 39675 s2: 96G is:  115 48
 P+Q: 2  2s1: 12 s2: 4G is:  2 2
 P+Q: 5  200s1: 75 s2: 400G is:  5 200
 P+Q: 159  114s1: 75843 s2: 228G is:  159 114
 P+Q: 174  163s1: 90828 s2: 326G is:  174 163
 P+Q: 181  209s1: 98283 s2: 418G is:  181 209
 P+Q: 136  11s1: 55488 s2: 22G is:  136 11
 P+Q: 147  97
Array contains:  115 48 2 2 5 200 159 114 174 163 181 209 136 11 147 97bin1 in cpk: 11010011Gnext:  2 2delta is: 189
 P+Q: 156  10Gnext:  159 114delta is: 105
 P+Q: 160  203Gnext:  136 11delta is: 8
 P+Q: 190  190Gnext:  147 97delta is: 169
 P+Q: 161  69
Final G:  161 69
K2 is:  161 69Binary of na: 0011001011
Calculation for pb: 
cnt is: 8s1: 12 s2: 4G is:  2 2
 P+Q: 5  200s1: 75 s2: 400G is:  5 200
 P+Q: 159  114s1: 75843 s2: 228G is:  159 114
 P+Q: 174  163s1: 90828 s2: 326G is:  174 163
 P+Q: 181  209s1: 98283 s2: 418G is:  181 209
 P+Q: 136  11s1: 55488 s2: 22G is:  136 11
 P+Q: 147  97s1: 64827 s2: 194G is:  147 97
 P+Q: 133  48
Array contains:  2 2 5 200 159 114 174 163 181 209 136 11 147 97 133 48bin1 in cpk: 11010011Gnext:  5 200delta is: 66
 P+Q: 129  56Gnext:  174 163delta is: 204
 P+Q: 168  6Gnext:  147 97delta is: 66
 P+Q: 32  108Gnext:  133 48delta is: 154
 P+Q: 130  203
Final G:  130 203
pb is:  130 203Binary of na: 0001111001
cnt is: 7s1: 50700 s2: 406G is:  130 203
 P+Q: 31  6s1: 2883 s2: 12G is:  31 6
 P+Q: 121  210s1: 43923 s2: 420G is:  121 210
 P+Q: 117  142s1: 41067 s2: 284G is:  117 142
 P+Q: 160  8s1: 76800 s2: 16G is:  160 8
 P+Q: 168  205s1: 84672 s2: 410G is:  168 205
 P+Q: 84  1
Array contains:  130 203 31 6 121 210 117 142 160 8 168 205 84 1bin1 in cpk: 1001111Gnext:  117 142delta is: 167
 P+Q: 1  29Gnext:  160 8delta is: 183
 P+Q: 201  85Gnext:  168 205delta is: 169
 P+Q: 129  56Gnext:  84 1delta is: 95
 P+Q: 161  69
Final G:  161 69
K1 is:  161 69
Compare K1 and K2: 
Keys are same........!Do you want to continue:(0/1)0

akshay@akshay-pc:~$ 





*/

function[y]=circonv(xn,hn,N)
N1=length(xn);
N2=length(hn);
xn1=[xn zeros(1,(N-N1))];
hn1=[hn zeros(1,(N-N2))];
for n=1:1:N
    m=n-1;
    p=0:1:N-1;
    q=mod(p-m,N);
    hm=hn1(q+1);
    H(n,:)=hm;
end
H'
y=H'*xn1'
end
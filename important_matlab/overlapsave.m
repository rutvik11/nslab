%kriti nagori
%k-48

function[w]=overlapsave(xn,hn,N)
if(N<length(hn))
    error('N>=length(hn)');
end
Nx=length(xn);
M=length(hn);
M1=M-1;
L=N-M1;
x=[zeros(1,(M-1)) xn zeros(1,(N-1))];
h=[hn zeros(1,(N-M))];
k=floor((Nx+M1-1)/L);
y=zeros(k+1,N);
for i=0:1:k
    xk=x(i*L+1:i*L+N);
    y(i+1,:)=circonv(xk,h,N);
end
y=y(:,(M:N))';
w=y(:)';
end
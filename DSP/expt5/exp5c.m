clc;
close all;
clear all;
x1=[2 1 2 1];
x2=[1 2 3 4];
L=length(x1);
L1=length(x2);
N=4;
x3=[x1 zeros(1,(N-L))];
x4=[x2 zeros(1,(N-L1))];
for k=0:1:N-1;
    X1(k+1)=0;
    X2(k+1)=0;
    for n=0:1:N-1;
        X1(k+1)=X1(k+1)+(x3(n+1)*exp((-2*pi*1i*k*n)/N));
        X2(k+1)=X2(k+1)+(x4(n+1)*exp((-2*pi*1i*k*n)/N));
    end
end
Y=X1.*X2;
for n=0:1:N-1;
    x5(n+1)=0;
    for k=0:1:N-1;
        x5(n+1)=(x5(n+1)+(1/N)*(Y(k+1)*exp((2*pi*1i*k*n)/N)));
    end
end
x1
x2
x5


%circular freq shift 
clc;
close all;
clear all;
x=[1 2 3 4];
L=length(x);
N=4;
l=2;
x1=[x zeros(1,(N-L))];
for k=0:1:N-1;
    X1(k+1)=0;
    for n=0:1:N-1;
        X1(k+1)=X1(k+1)+(x1(n+1)*exp((-2*pi*1i*k*n)/N));
    end
end
for n=0:1:N-1;
    x2(n+1)=x1(n+1)*exp((2*pi*1i*n*l)/N);
end
for k=0:1:N-1;
    X2(k+1)=0;
    for n=0:1:N-1;
        X2(k+1)=X2(k+1)+(x2(n+1)*exp((-2*pi*1i*k*n)/N));
    end
end
X1
X2

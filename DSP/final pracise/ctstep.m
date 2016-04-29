clc;
clear all;
close all;
x=[1 2 3 4]
l=length(x);
N=4;
x1=[x,zeros(1,(N-1));
    for k=0:1:N-1
    X(k+1)=0;
    for n=0:1:N-1
        X(k+1)=X(k+1)+(x(n+1)*exp((-i*2*pi*k*n)/N));
    end
end
diplay(x)
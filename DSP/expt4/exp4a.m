clc;
clear all
close all;
x=[1 2 3 4];
L=length(x);
N=4;
x1=[x zeros(1,(N-L))];
for k=0:1:N-1;
    X1(k+1)=0;
    for n=0:1:N-1;
        X1(k+1)=X1(k+1)+(x1(n+1)*exp((-2*pi*1i*k*n)/N));
    end
end
X1
subplot(2,1,1),stem(abs(X1));
title('magnitude plot');
subplot(2,1,2),stem(angle(X1));
title('phase plot');
        
    
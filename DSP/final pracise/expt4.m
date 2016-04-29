clc;
clear all;
close all;
x=[1 2 3 4]
L=length(x);
N=4;
x1=[x zeros(1,(N-L))];
for k=0:1:N-1;
    X(k+1)=0;
    for n=0:1:N-1;
     X(k+1)= X(k+1)+(x(n+1)*exp((-2*i*pi*k*n)/(N)));
    end
end
X
subplot(2,1,1);stem(abs(X))
title('magnitude plot')
subplot(2,1,2);stem(angle(X))
title('phase plot')
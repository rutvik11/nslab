clc;
close all; clear all;
x1=[1 2 3 4 5 2 3 1]
x2=[1 1 3 2 5 4 3 2]
N=8;
for k=0:1:N-1;
    X1(k+1)=0;
    X2(k+1)=0;
    for n=0:1:N-1;
        X1(k+1)=X1(k+1)+(x1(n+1)*exp((-2*pi*i*k*n)/(N)));
        X2(k+1)=X2(k+1)+(x2(n+1)*exp((-2*pi*i*k*n)/(N)));
    end
end
X1
X2
subplot(4,1,1);stem(abs(X1))
title('magnitude plot')
subplot(4,1,2);stem(angle(X1))
title('phase plot')
subplot(4,1,3);stem(abs(X2))
title('magnitude plot')
subplot(4,1,4);stem(angle(X2))
title('phase plot')
    
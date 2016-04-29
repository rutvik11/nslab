clc;
close all;
clear all;
X=[10.0000    -2.0000+2.0000i  -2.0000-0.0000i  -2.0000-2.0000i]
L=length(X);
N=4;
X1=[X zeros(1,(N-L))]
for n=0:1:N-1;
    x(n+1)=0;
    for k=0:1:N-1;
        x(n+1)=x(n+1)+(X(k+1)*exp((2*pi*i*k*n)/(N)));
    end
    x(n+1)=((x(n+1))/(N))
end
x
subplot(2,1,1);stem(abs(x))
title('magnitude plot')
subplot(2,1,2);stem(angle(x))
title('phase plot')
        
        

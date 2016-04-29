clc;
close all;
X=[10 -2+2i -2+0i -2-2i];
L=length(X);
N=4;
X1=[X zeros(1,(N-L))];
for n=0:1:N-1;
    x1(n+1)=0;
    for k=0:1:N-1;
        x1(n+1)=(x1(n+1)+(1/N)*(X1(k+1)*exp((2*pi*1i*k*n)/N)));
    end
end
x1
subplot(2,1,1),stem(abs(x1));
title('magnitude plot');
subplot(2,1,2),stem(angle(x1));
title('phase plot');
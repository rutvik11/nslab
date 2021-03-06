%circular time shift
clc;
close all;
clear all;
x1=[1 2 3 4];
L=length(x1);
N=4;
l=2;
%x1=[x zeros(1,(N-L))];
for k=0:1:N-1;
    X1(k+1)=0; 
    for n=0:1:N-1;
        X1(k+1)=X1(k+1)+(x1(n+1)*exp((-2*pi*1i*k*n)/N));
    end
end
for k=0:1:N-1
    X2(k+1)=X1(k+1)*exp((-2*pi*i*k*l)/N);
end
for n=0:1:N-1;
    x2(n+1)=0;
    for k=0:1:N-1;
        x2(n+1)=(x2(n+1)+(1/N)*(X2(k+1)*exp((2*pi*1i*k*n)/N)));
    end
end
x1
x2
 subplot(4,1,1),stem(abs(x1));
 title('magnitude plot');
 subplot(4,1,2),stem(angle(x1));
 title('phase plot');
 subplot(4,1,3),stem(abs(x1));
 title('magnitude plot');
 subplot(4,1,4),stem(angle(x1));
 title('phase plot');

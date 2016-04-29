clc;
clear all;
close all;
n=0:30;
for n=0:30
    x(n+1)=(0.9)^n;
end
n=0:30;
subplot(2,1,1);
stem(n,x(n+1));
xlabel('time');
ylabel('amplitude');
title('exponentially decresing signal');
for n=0:30
    x(n+1)=(1.4)^n;
end
n=0:30;
subplot(2,1,2);
stem(n,x(n+1));
xlabel('time');
ylabel('amplitude');
title('exponentially increasing signal');
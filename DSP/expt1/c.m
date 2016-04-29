%IMPULSE SIGNAL

clc;
clear all;
close all;
n=-10:20;
k=input('enter the number');
x=[zeros(1,10) 1 zeros(1,20)];
subplot(2,1,1);
stem(n,x);
xlabel('time');
ylabel('amplitude');
title('Impulse signal');
y=[zeros(1,10+k) 1 zeros(1,20-k)];
subplot(2,1,2);
stem(n,y);
xlabel('time');
ylabel('amplitude');
title('Shifted impulse signal');


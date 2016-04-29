%DISCRETE UNIT STEP SIGNAL

clc;
clear all;
close all;
n=-10:20;
k=input('enter the number');
x=[zeros(1,10) ones(1,21)];
subplot(2,1,1);
stem(n,x);
xlabel('time');
ylabel('amplitude');
title('unit step signal');
y=[zeros(1,10+k) ones(1,21-k)];
subplot(2,1,2);
stem(n,y);
xlabel('time');
ylabel('amplitude');
title('shifted unit step signal');

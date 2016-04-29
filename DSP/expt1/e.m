%DAMP AND UNDAMP SIGNAL


clc;
clear all;
close all;
t=0:0.01:5;
f=5;
x=exp(-t).*cos(2*pi*f*t);
subplot(2,1,1);
plot(t,x);
xlabel('time');
ylabel('amplitude');
title('damp signal')
y=exp(t).*cos(2*pi*f*t);
subplot(2,1,2);
plot(t,y);
xlabel('time');
ylabel('amplitude');
title('undamp signal')


%a notch filter that filter 50HZ  noise
clc;
close all;
clear all;
t=0:0.001:2;
x=cos(2*pi*50*t);
x1=cos(2*pi*50*t);
b=[1 -1.9022 1];
a=[1 -1.8072 0.9025]
y=filter(b,a,x);
w=0:0.01:pi;
h=freqz(b,a,w);
subplot(3,1,2),plot(w/pi,abs(h));
xlabel('time'),ylabel('x(t)')
subplot(3,1,1),plot(t,x);
xlabel('time'),ylabel('magnitude')
subplot(3,1,3),plot(t,y);
xlabel('time'),ylabel('output of the notch filter')
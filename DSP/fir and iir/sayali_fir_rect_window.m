clc;
clear all;
close all;
N=11;
fc=0.25;
hn=fir1((N-1),fc,rectwin(N))
fvtool(hn)
w=0:0.01:pi;
H=freqz(hn,1,w);
plot(abs(H));
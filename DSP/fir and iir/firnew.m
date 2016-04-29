clc;
clear all;
close all;
N=11;
fc=0.5;
hn=fir1((N-1),fc,hamming(N))
fvtool(hn)
w=0:0.01:pi;
H=freqz(hn,1,w);
plot(abs(H));
% clc;
% close all;
% clear all;
n=input('Enter the length of ramp sequence N = ');  % Get the length
s=input(' Enter the slop of the ramp S = ');  % Get the slop of the ramp
t=0:1:n;
plot(t,s*t);
ylabel ('Amplitude');
xlabel ('Time');
TITLE ('Ramp signal');

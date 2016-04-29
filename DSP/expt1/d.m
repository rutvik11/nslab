%RAMP SIGNAL

clc
clear all;
t=40;
%t=input('Enter time period');
for i=1:1:40
    if(t>0)
        y(i)=i
    else
        y(i)=0
    end
end
t=1:1:40
plot(t,y(t));
xlabel('time');
ylabel('amplitude');
title('Unit ramp signal');

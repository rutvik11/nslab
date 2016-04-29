clc;
clear all;
close all;
t=0:40;
for i=0:1:40
        y(i+1)=1
end
i=0:1:40
plot(t,y(i+1));
xlabel('time');
ylabel('amplitude');
title('Unit step signal');

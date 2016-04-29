t=0:0.1:10;
x=exp(t)
subplot(2,1,1);
plot(t,x)
title('exponentially increasing')
y=exp(-t)
subplot(2,1,2);
plot(t,y)
title('exponentially decreasing')



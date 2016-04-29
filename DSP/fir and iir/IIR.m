fs=2000;
Wp=200/1000;
Ws=300/1000;
Rp=1.25;
Rs=15;
[N,Wc]=buttord(Wp,Ws,Rp,Rs)
[z,p,k]=butter(N,200/1000)
[b,a]=butter(N,200/1000)
zplane(b,a);
title('Pole-Zero Plot');
[H,f]=freqz(b,a,256,fs);
figure;
plot(f,abs(H));
title('Frequency Response');
fvtool(H);

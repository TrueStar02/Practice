function [] = FreqGraph(b,a,w)
%调用freqs函数并画图
h=freqs(b,a,w);
subplot(2,1,1);
plot(w,abs(h));
grid on;
xlabel('\omega(rad/s)');
ylabel('|H(j\omega)|');
title('Amplitude frequency response of H(jw)');
subplot(2,1,2);
plot(w,angle(h));
grid on;
xlabel('\omega(rad/s)');
ylabel('\phi(\omega)');
title('Phase frequency response of H(jw)');
end
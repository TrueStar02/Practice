function [] = NumricFourier(dt,t,ft,M,w0)
%数值计算傅里叶变换并画图
%   dt:采样间隔
%   t:时间样值
%   ft:函数样值
%   M:频率取样数
%   w0:频率取样范围
k=0:M;
w=k*w0/M;
Fw=abs(ft*exp(-1i*(t')*w)*dt);
W=[-fliplr(w),w(2:M+1)];
FW=[fliplr(Fw),Fw(2:M+1)];
subplot(2,1,1);
plot(t,ft);
grid on;
xlabel('t');
ylabel('f(t)');
title('The graph of f(t)');
subplot(2,1,2);
plot(W,FW);
grid on;
xlabel('w');
ylabel('F(w)');
title('Amplitude Spectrogram of f(t)');
end
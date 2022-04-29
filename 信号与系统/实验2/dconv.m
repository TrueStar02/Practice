function [f,k] = dconv(f1,f2,k1,k2)
f=conv(f1,f2)
k0=k1(1)+k2(1);
k3=length(f1)+length(f2)-2;
k=k0:k0+k3
subplot(2,2,1)
stem(k1,f1)
title('f1(k)')
xlabel('k')
ylabel('f1(k)')
subplot(2,2,2)
stem(k2,f2)
title('f2(k)')
xlabel('k')
ylabel('f2(k)')
subplot(2,2,3)
stem(k,f)
title('f(k)=f1(k)*f2(k)')
xlabel('k')
ylabel('f(k)')
h=get(gca,'position');
h(3)=2.5*h(3);
set(gca,'position',h)
end


function [m] = FirstBiggerThan(k)
a=[1,1];
i=2;
while a(i)<=k
a(i+1)=a(i)+a(i-1);
i=i+1;
end
m=a(i)
end


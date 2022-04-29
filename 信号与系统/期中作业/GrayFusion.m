function [] = GrayFusion(GLow,GHigh,d0)
    FwLow=fftshift(fft2(im2double(GLow)));
    [M,N]=size(GLow);
    m_mid=floor(M/2);
    n_mid=floor(N/2);
    HLow=zeros(M,N);
    for i=1:M
        for j=1:N
            d = ((i-m_mid)^2+(j-n_mid)^2);
            HLow(i,j) = exp(-(d)/(2*(d0^2)));      
        end
    end
    Fw2Low=HLow.*FwLow;
    G2Low=uint8(256*real(ifft2(ifftshift(Fw2Low))));
    FwHigh=fftshift(fft2(im2double(GHigh)));
    HHigh=zeros(M,N);
    for i=1:M
        for j=1:N
            d = ((i-m_mid)^2+(j-n_mid)^2);
            HHigh(i,j) = 1-exp(-(d)/(2*(d0^2)));      
        end
    end
    Fw2High=HHigh.*FwHigh;
    G2High=uint8(256*real(ifft2(ifftshift(Fw2High))));
    G2=floor((G2Low+G2High)/2);
    imshow(G2);
end


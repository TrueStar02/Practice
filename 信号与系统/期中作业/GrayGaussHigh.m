function [] = GrayGaussHigh(G,d0)
    Fw=fftshift(fft2(im2double(G)));
    [M,N]=size(G);
    m_mid=floor(M/2);
    n_mid=floor(N/2);
    H=zeros(M,N);
    for i=1:M
        for j=1:N
            d = ((i-m_mid)^2+(j-n_mid)^2);
            H(i,j) = 1-exp(-(d)/(2*(d0^2)));      
        end
    end
    Fw2=H.*Fw;
    G2=uint8(256*real(ifft2(ifftshift(Fw2))));
    subplot(2,2,1);
    imshow(G);
    title('原始图片');
    subplot(2,2,2);
    imshow(log(Fw+1));
    title('原始对数频谱');
    subplot(2,2,3);
    imshow(G2);
    title('滤波后图片');
    subplot(2,2,4);
    imshow(log(Fw2+1));
    title('滤波后对数频谱');
end


function [] = ColorGaussHigh(G0,d0)
    R=G0(:,:,1);
    G=G0(:,:,2);
    B=G0(:,:,3);
    
    [M,N]=size(R);
    FwR=fftshift(fft2(im2double(R)));
    FwG=fftshift(fft2(im2double(G)));
    FwB=fftshift(fft2(im2double(B)));
    m_mid=floor(M/2);
    n_mid=floor(N/2);
    H=zeros(M,N);
    for i=1:M
        for j=1:N
            d = ((i-m_mid)^2+(j-n_mid)^2);
            H(i,j) =1-exp(-(d)/(2*(d0^2)));      
        end
    end
    FwR2=H.*FwR;
    FwG2=H.*FwG;
    FwB2=H.*FwB;
    RR=uint8(256*real(ifft2(ifftshift(FwR2))));
    GG=uint8(256*real(ifft2(ifftshift(FwG2))));
    BB=uint8(256*real(ifft2(ifftshift(FwB2))));
    G2(:,:,1)=RR(:,:,1);
    G2(:,:,2)=GG(:,:,1);
    G2(:,:,3)=BB(:,:,1);
    imshow(G2);
end


function [] = ColorFusion(G0Low,G0High,d0)
    RLow=G0Low(:,:,1);
    GLow=G0Low(:,:,2);
    BLow=G0Low(:,:,3);
    [M,N]=size(RLow);
    FwRLow=fftshift(fft2(im2double(RLow)));
    FwGLow=fftshift(fft2(im2double(GLow)));
    FwBLow=fftshift(fft2(im2double(BLow)));
    m_mid=floor(M/2);
    n_mid=floor(N/2);
    HLow=zeros(M,N);
    HHigh=zeros(M,N);
    for i=1:M
        for j=1:N
            d = ((i-m_mid)^2+(j-n_mid)^2);
            HLow(i,j) =exp(-(d)/(2*(d0^2)));     
            HHigh(i,j) =1-HLow(i,j);    
        end
    end
    FwR2Low=HLow.*FwRLow;
    FwG2Low=HLow.*FwGLow;
    FwB2Low=HLow.*FwBLow;
    RRLow=uint8(256*real(ifft2(ifftshift(FwR2Low))));
    GGLow=uint8(256*real(ifft2(ifftshift(FwG2Low))));
    BBLow=uint8(256*real(ifft2(ifftshift(FwB2Low))));
    G2Low(:,:,1)=RRLow(:,:,1);
    G2Low(:,:,2)=GGLow(:,:,1);
    G2Low(:,:,3)=BBLow(:,:,1);
    RHigh=G0High(:,:,1);
    GHigh=G0High(:,:,2);
    BHigh=G0High(:,:,3);
    FwRHigh=fftshift(fft2(im2double(RHigh)));
    FwGHigh=fftshift(fft2(im2double(GHigh)));
    FwBHigh=fftshift(fft2(im2double(BHigh)));
    FwR2High=HHigh.*FwRHigh;
    FwG2High=HHigh.*FwGHigh;
    FwB2High=HHigh.*FwBHigh;
    RRHigh=uint8(256*real(ifft2(ifftshift(FwR2High))));
    GGHigh=uint8(256*real(ifft2(ifftshift(FwG2High))));
    BBHigh=uint8(256*real(ifft2(ifftshift(FwB2High))));
    G2High(:,:,1)=RRHigh(:,:,1);
    G2High(:,:,2)=GGHigh(:,:,1);
    G2High(:,:,3)=BBHigh(:,:,1);
    G2=floor((G2Low+G2High)/2);
    imshow(G2);
end


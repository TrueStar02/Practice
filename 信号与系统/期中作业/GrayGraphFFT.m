function [] = GrayGraphFFT(G)
    Fw=fftshift(fft2(im2double(G)));
    R=real(Fw);
    lnR=log(R+1);
    subplot(1,3,1);
    imshow(G);
    title('原始图片');
    subplot(1,3,2);
    imshow(R);
    title('傅里叶频谱');
    subplot(1,3,3);
    imshow(lnR);
    title('对数傅里叶频谱');
end
class Complex
{   private:
        double re;
        double im;
    public:
        Complex(double r,double i):re(r),im(i){}
      friend Complex add(const Complex& a,const Complex& b){return Complex(a.re+b.re,a.im+b.im);}
       friend Complex multiply(const Complex& a,const Complex& b){return Complex(a.re*b.re-a.im*b.im,a.im*b.re+a.re*b.im);}
        void print(void)
        {  using namespace std;
            if(re!=0||re==0&&im==0)
             cout<<re;
            if(im>0&&re!=0)cout<<"+"<<im<<"i"<<endl;
            else if(im==0)cout<<endl;
            else cout<<im<<"i"<<endl;
        }
};
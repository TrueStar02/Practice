class Rectangle
{
  private:
    double width, height;
  public:
    Rectangle():width(1),height(1){}
    Rectangle(double w, double h):width(w),height(h){}
    double getWidth()const{return width;}
    double getHeight()const{return height;}
    void setWidth(double w){width=w;}
    void setHeight(double h){height=h;}
    double getArea()const{return width*height;}
    double getPerimeter()const{return 2*width+2*height; } 
};
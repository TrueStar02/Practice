   #include "Double.h"
   Double::Double() {data=0;}
        Double::Double(double d):data(d){}
     double Double::getDouble() const{return data;}
     void Double::setDouble(double d){data=d;}
     void Double::add(const Double &other){data+=other.data;}
     void Double::sub(const Double &other){data-=other.data;}
     void Double::mul(const Double &other){data*=other.data;}
     bool Double::div(const Double &other)
     {if(!other.data)return 0;
         data/=other.data;return 1;}
 #include "Time.h"
 #include<ctime>
 Time::Time()
 {
     time_t timer;
    time(&timer);
    Second=timer%60;
            Hour=timer/3600;
            Minute=(timer%3600)/60;

 }
         Time::Time(int totalSeconds)
         {  Second=totalSeconds%60;
            Hour=totalSeconds/3600;
            Minute=(totalSeconds%3600)/60;

         }
        int  Time::getHour() const{return Hour;}
        int  Time::getMinute()const{return Minute;}
        int  Time::getSecond()const{return Second;}
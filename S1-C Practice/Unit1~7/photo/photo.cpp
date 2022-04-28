#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{  ifstream fin("photo.in") ;
   ofstream fout("photo.out");
   short in[21][31];
   char out[21][31];
   int x,y,z;
   for(x=1;x<=20;x++)
   for(y=1;y<=30;y++)
   fin>>in[x][y];
   for(z=1;z<=3;z++)
   for(x=1;x<=20;x++)
   for(y=1;y<=30;y++)
   {if(x!=1&&x!=20&&y!=1&&y!=30)
    {if((in[x][y]-in[x-1][y]>1||in[x][y]-in[x-1][y]<-1)&&(in[x][y]-in[x+1][y]>1||in[x][y]-in[x+1][y]<-1)
      &&(in[x][y]-in[x][y-1]>1||in[x][y]-in[x][y-1]<-1)&&(in[x][y]-in[x][y+1]>1||in[x][y]-in[x][y+1]<-1))
     in[x][y]=(in[x-1][y]+in[x+1][y]+in[x][y-1]+in[x][y+1]+2)/4;
    }
    else if(x==1&&y!=1&&y!=30)
    {if((in[x][y]-in[x+1][y]>1||in[x][y]-in[x+1][y]<-1)
      &&(in[x][y]-in[x][y-1]>1||in[x][y]-in[x][y-1]<-1)&&(in[x][y]-in[x][y+1]>1||in[x][y]-in[x][y+1]<-1))
     in[x][y]=(in[x+1][y]+in[x][y-1]+in[x][y+1]+1.5)/3;
    }
    else if(x==20&&y!=1&&y!=30)
    {if((in[x][y]-in[x-1][y]>1||in[x][y]-in[x-1][y]<-1)
      &&(in[x][y]-in[x][y-1]>1||in[x][y]-in[x][y-1]<-1)&&(in[x][y]-in[x][y+1]>1||in[x][y]-in[x][y+1]<-1))
     in[x][y]=(in[x-1][y]+in[x][y-1]+in[x][y+1]+1.5)/3;
    }
    else if(x!=1&&x!=20&&y==1)
    {if((in[x][y]-in[x-1][y]>1||in[x][y]-in[x-1][y]<-1)&&(in[x][y]-in[x+1][y]>1||in[x][y]-in[x+1][y]<-1)
      &&(in[x][y]-in[x][y+1]>1||in[x][y]-in[x][y+1]<-1))
     in[x][y]=(in[x-1][y]+in[x+1][y]+in[x][y+1]+1.5)/3;
    }
    else if(x!=1&&x!=20&&y==30)
    {if((in[x][y]-in[x-1][y]>1||in[x][y]-in[x-1][y]<-1)&&(in[x][y]-in[x+1][y]>1||in[x][y]-in[x+1][y]<-1)
      &&(in[x][y]-in[x][y-1]>1||in[x][y]-in[x][y-1]<-1))
     in[x][y]=(in[x-1][y]+in[x+1][y]+in[x][y-1]+1.5)/3;
    }
    else if(x==1&&y==1)
    {if((in[x][y]-in[x+1][y]>1||in[x][y]-in[x+1][y]<-1)
      &&(in[x][y]-in[x][y+1]>1||in[x][y]-in[x][y+1]<-1))
     in[x][y]=(in[x+1][y]+in[x][y+1]+1)/2;
    }
    else if(x==1&&y==30)
    {if((in[x][y]-in[x+1][y]>1||in[x][y]-in[x+1][y]<-1)
      &&(in[x][y]-in[x][y-1]>1||in[x][y]-in[x][y-1]<-1))
     in[x][y]=(in[x+1][y]+in[x][y-1]+1)/2;
    }
    else if(x==20&&y==30)
    {if((in[x][y]-in[x-1][y]>1||in[x][y]-in[x-1][y]<-1)
      &&(in[x][y]-in[x][y-1]>1||in[x][y]-in[x][y-1]<-1))
     in[x][y]=(in[x-1][y]+in[x][y-1]+1)/2;
    }
    else
    {if((in[x][y]-in[x-1][y]>1||in[x][y]-in[x-1][y]<-1)
      &&(in[x][y]-in[x][y+1]>1||in[x][y]-in[x][y+1]<-1))
     in[x][y]=(in[x-1][y]+in[x][y+1]+1)/2;
    }
   }
   for(x=1;x<=20;x++)
   for(y=1;y<=30;y++)
   switch(in[x][y])
   {case 0:out[x][y]=' ';
           break;
    case 1:out[x][y]='.';
           break;
    case 2:out[x][y]='\'';
           break;
    case 3:out[x][y]=':';
           break;
    case 4:out[x][y]='~';
           break;
    case 5:out[x][y]='*';
           break;
    case 6:out[x][y]='=';
           break;
    case 7:out[x][y]='&';
           break;
    case 8:out[x][y]='%';
           break;
    case 9:out[x][y]='#';
           break;
   
   }
   for(x=1;x<=20;x++)
   {for(y=1;y<=30;y++)
    fout<<out[x][y];
    fout<<endl;
   } 
    
   
}

#include<iostream>
using namespace std;
int main()
{   int n,x,y;
    cin>>n;
    char cache[n];
    for(x=0;x<n;x++)
        cache[x]='\0';
    string str;
    cin>>str;
    bool flag;
    int read=0;
    int count=0;
    int index,max,res;
    for(x=0;x<str.length();x++)
    {   flag=0;
        for(y=0;y<count;y++)
            if(cache[y]==str[x])
            {   flag=1;
                break;
            }    
        if(!flag)
        {   cout<<"Failed ";
            read++;
            if(count<n)
            {   cout<<"Add "<<str[x];
                cache[count]=str[x];
                count++;
            }    
            else
            {   index=0;
                max=0;
                for(y=0;y<n;y++)
                {   res=str.find(cache[y],x+1);
                    if(res==string::npos)
                    {   index=y;
                        break;
                    }
                    else if(res>max)
                    {   index=y;
                        max=res;
                    }

                }
                if(str.find(str[x],x+1)!=string::npos&&str.find(str[x],x+1)<max)
                {   cout<<cache[index]<<"->"<<str[x];
                    cache[index]=str[x];
                }    


            }

        }
        else
            cout<<"Success";
        cout<<endl;
    }
    cout<<read<<endl;
    return 0;
}
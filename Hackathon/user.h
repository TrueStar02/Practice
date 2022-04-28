#ifndef USER_H_
#define USER_H_
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct simple
{   int number;
    bool isvalid;
};
class Activity;
class user
{   public:
        char name[30];
        int number;
        char password[16];
        int type;
        fstream * activ;
        user(){}
        user(const char * n,int no,const char * pas,int t);
        bool ChangePassword(const char * pas);
        bool Join(fstream & a_ptr,int no);
        bool Cancel(fstream & a_ptr,int no);
        void GetData(fstream & a_ptr); 
        void SendActivity(Activity a,fstream & a_ptr);
        void CancelActivity();
        void AddActivity(Activity a,fstream & a_ptr);
        void DeleteActivity();
};
class Activity
{   public:
        char name[30];
        char introduction[170];
        int number;
        int limit;
        int cur;
        int hours;
        int sport;
        bool isvalid;
        fstream * user_ptr;
        Activity(){}
        Activity(const char * n,const char * intro,int num,int lim,int h,int s);
        void print();
        void ListPerson(void);
        ~Activity(){}
};
user::user(const char * n,int no,const char * pas,int t):number(no),type(t)
{   strncpy(name,n,29);
    for(int x=0;x<=15;x++)
        password[x]=pas[x];
    for(int x=0;x<=15;x++)
        cout<<password[x];
    cout<<endl;
    for(int x=0;x<=15;x++)
        cout<<pas[x];
    cout<<endl;
}
bool user::ChangePassword(const char * pas)
{   strncpy(password,pas,16);
    return 1;
}
bool user::Join(fstream & a_ptr,int no)
{   a_ptr.seekg(0);
    activ->seekp(0);
    Activity temp;
    while(!a_ptr.eof())
    {   a_ptr.read((char *)(&temp),sizeof(Activity));
        if(temp.isvalid&&temp.number==no)
        {   a_ptr.seekg(-sizeof(Activity),ios_base::cur);
            break;
        }
    }
    if(!a_ptr.eof())
    {   temp.user_ptr=new fstream;
        ostringstream strout;
        strout<<temp.number;
        temp.user_ptr->open(strout.str().c_str());
        simple s;
        while(!temp.user_ptr->eof())
        {   temp.user_ptr->read((char *)(&s),sizeof(simple));
            if(!s.isvalid)
            {   temp.user_ptr->seekp(-sizeof(simple),ios_base::cur);
                s.number=number;
                s.isvalid=1;
                temp.user_ptr->write((char *)(&s),sizeof(simple));
                break;
            }
        }
        if(temp.user_ptr->eof()) 
        {   temp.user_ptr->clear();
            s.number=number;
            s.isvalid=1;
            temp.user_ptr->write((char *)(&s),sizeof(simple));
        }
        activ->clear();
        activ->seekg(0);
        while(!activ->eof())
        {   activ->read((char *)(&s),sizeof(simple));
            if(!s.isvalid)
            {   activ->seekp(-sizeof(simple),ios_base::cur);
                s.number=no;
                s.isvalid=1;
                activ->write((char *)(&s),sizeof(simple));
                break;
            }
        }
        if(activ->eof()) 
        {   activ->clear();
            s.number=no;
            s.isvalid=1;
            activ->write((char *)(&s),sizeof(simple));
        }
        return 1;
    }
    else
        return 0;
}
bool user::Cancel(fstream & a_ptr,int no)
{   a_ptr.seekg(0);
    Activity temp;
    while(!a_ptr.eof())
    {   a_ptr.read((char *)(&temp),sizeof(Activity));
        if(temp.isvalid&&temp.number==no)
        {   a_ptr.seekg(-sizeof(Activity),ios_base::cur);
            break;
        }
    }
    if(!a_ptr.eof())
    {   temp.user_ptr=new fstream;
        ostringstream strout;
        strout<<temp.number;
        temp.user_ptr->open(strout.str().c_str());
        simple s;
        while(!temp.user_ptr->eof())
        {   temp.user_ptr->read((char *)(&s),sizeof(simple));
            if(s.isvalid&&s.number==number)
            {   temp.user_ptr->seekp(-sizeof(simple),ios_base::cur);
                s.isvalid=0;
                temp.user_ptr->write((char *)(&s),sizeof(simple));
                break;
            }
        }
        if(temp.user_ptr->eof()) 
            return 0;
        activ->clear();
        activ->seekg(0);
        while(!activ->eof())
        {   activ->read((char *)(&s),sizeof(simple));
            if(s.isvalid&&s.number==temp.number)
            {   activ->seekp(-sizeof(simple),ios_base::cur);
                s.isvalid=0;
                activ->write((char *)(&s),sizeof(simple));
                break;
            }
            return 1;
        }
        if(activ->eof()) 
            return 0;
    }
    return 0;
}
void user::GetData(fstream & a_ptr)
{   cout<<"Name:"<<name<<endl;
    cout<<"Number:"<<number<<endl;
    cout<<"Type:"<<type<<endl;
    cout<<"Activity List:\n";
    simple s;
    while(activ->read((char *)(&s),sizeof(simple)))
    {   
        if(s.isvalid)
        {   a_ptr.clear();
            a_ptr.seekg(0);
            Activity temp;
            while(!a_ptr.eof())
            {   a_ptr.read((char *)(&temp),sizeof(Activity));
                if(temp.number==s.number)
                {   temp.print();
                    break;
                }                    
            }
        }
    }
}
void user::SendActivity(Activity a,fstream & a_ptr)
{   a_ptr.seekg(0);
    Activity temp;
    
    while(a_ptr.read((char *)(&temp),sizeof(Activity)))
    {   if(!temp.isvalid)
        {   a_ptr.seekp(-sizeof(Activity),ios_base::cur);
            a_ptr.write((char *)(&a),sizeof(Activity));
            break;
        }
        
    }
    if(a_ptr.eof())
    {   a_ptr.clear();
        a_ptr.write((char *)(&a),sizeof(Activity));
    }
    simple sp,s;
    sp.isvalid=1;
    sp.number=a.number;
    activ->clear();
    activ->seekg(0);
    while(activ->read((char *)(&s),sizeof(simple)))
    {   if(!s.isvalid)
        {   activ->seekp(-sizeof(simple),ios_base::cur);
            activ->write((char *)(&sp),sizeof(simple));
            break;
        }
    }
    if(activ->eof()) 
    {   activ->clear();
        activ->write((char *)(&sp),sizeof(simple));
    }
}
/*void user::CancelActivity()
{}*/
void user::AddActivity(Activity a,fstream & a_ptr)
{   a_ptr.seekg(0);
    Activity temp;
    while(a_ptr.read((char *)(&temp),sizeof(Activity)))
    {   if(!temp.isvalid)
        {   a_ptr.seekp(-sizeof(Activity),ios_base::cur);
            a_ptr.write((char *)(&a),sizeof(Activity));
            break;
        }
       
    } 
    if(a_ptr.eof())
    {   a_ptr.clear();
        a_ptr.write((char *)(&a),sizeof(Activity));
    }
}
Activity::Activity(const char * n,const char * intro,int num,int lim,int h,int s):number(num),limit(lim),cur(0),hours(h),sport(s),isvalid(1)
{   strcpy(name,n);
    strcpy(introduction,intro);
}
/*void user::DeleteActivity()
{}*/
void Activity::print()
{   cout<<"Activity:"<<name<<endl;
    cout<<"Introduction:"<<introduction<<endl;
    cout<<"Number:"<<number<<endl;
    cout<<"Sports Score:"<<sport<<endl;
    cout<<"Time"<<hours<<"h\n";
}
/*void Activity::ListPerson(void)
{   

}*/
#endif
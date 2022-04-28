#ifndef TRIE_H_
#define TRIE_H_  
#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
typedef vector<string> Dictionary;
template<class V>
class Trie
{   private:
        class Node
        {   public:
                V * value;
                Node * next[26];
                int size;
                Node():size(0)
                {   value=nullptr;
                    for(int x=0;x<26;x++)
                        next[x]=nullptr;
                }
                Node(const V & val):size(1)
                {   value=new V(val);
                    for(int x=0;x<26;x++)
                        next[x]=nullptr;
                }
        };
        Node * root;
        bool addKey(Node * n,const string & str,const V & val,int pos);
        bool delKey(Node * n,const string & str,int pos);
        void collect(Dictionary & dic,Node * n,string s) const;
        void match(const string & str,Dictionary & dic,Node * n,string s) const;
        int getSize(Node * n) const;
        void destroyNode(Node * n);
        string floorExact(const string & str,Node * n,string cur) const;
        string floorMax(const string & str,Node * n,string cur) const;
        string ceilExact(const string & str,Node * n,string cur)const;
        string ceilMin(const string & str,Node * n,string cur) const;
        void print(Node * n,int num)
        {   int x,y;
            for(x=0;x<26;x++)
            {   if(n->next[x]!=nullptr)
                {   for(y=0;y<num;y++)
                        cout.put('-');
                    cout<<char(x+97)<<" Num:"<<n->next[x]->size<<endl;
                    print(n->next[x],num+1);
                }
            }
        }
    public:
        Trie();
        void debug(void){print(root,0);}
        Trie(const Trie & tr)=delete;
        Trie(Trie && tr)=delete;
        ~Trie();
        Trie & operator=(const Trie & tr)=delete;
        Trie & operator=(Trie && tr)=delete;
        bool insert(const string & str,const V & val){return addKey(root,str,val,0);}
        bool erase(const string & str){return delKey(root,str,0);}
        bool contains(const string & str) const;
        V operator[](const string & str) const;
        V & operator[](const string & str); 
        Dictionary allKeys(void) const;
        Dictionary keyMatch(const string & str) const;
        string longestPrefix(const string & str) const;
        string floor(const string & str) const{return floorExact(str,root,"");}
        string ceiling(const string & str) const{return ceilExact(str,root,"");}
        int rank(const string & str) const;
        string select(int rk);
        void clear(void){destroyNode(root);}
};
template<class V>
bool Trie<V>::addKey(Node * n,const string & str,const V & val,int pos)
{   bool i;
    if(n->next[str[pos]-97]==nullptr)
    {   n->next[str[pos]-97]=new Node;
        if(str[pos+1]!='\0')
        {   i=addKey(n->next[str[pos]-97],str,val,pos+1);
            n->size+=i;
            return i;
        }
        else
        {   n->next[str[pos]-97]->value=new V(val);
            n->next[str[pos]-97]->size=1;
            n->size++;
            return 1;
        }
    }
    else 
    {   if(str[pos+1]!='\0')
        {   i=addKey(n->next[str[pos]-97],str,val,pos+1);
            n->size+=i;
            return i;
        }
        else if(n->next[str[pos]-97]->value==nullptr)
        {   n->next[str[pos]-97]->value=new V(val);
            n->next[str[pos]-97]->size++;
            n->size++;
            return 1;
        }
        else
            return 0;
    }
}
template<class V>
bool Trie<V>::delKey(Node * n,const string & str,int pos)
{   if(n->next[str[pos]-97]==nullptr)
        return 0;
    bool i=0;
    if(str[pos+1]=='\0')
    {   if(n->next[str[pos]-97]->value!=nullptr)
        {   delete n->next[str[pos]-97]->value;
            n->next[str[pos]-97]->value=nullptr;
            n->next[str[pos]-97]->size--;
            i=1;
        }
        else
            i=0;
    }
    else
        i=delKey(n->next[str[pos]-97],str,pos+1);
    if(i==1&&n->next[str[pos]-97]->size==0)
    {   delete n->next[str[pos]-97];
        n->next[str[pos]-97]=nullptr;
    }
    n->size-=i;
    return i;
}
template<class V>
void Trie<V>::collect(Dictionary & dic,Node * n,string s) const
{   if(n->value!=nullptr)
        dic.push_back(s);
    int x;
    for(x=0;x<26;x++)
        if(n->next[x]!=nullptr)
            collect(dic,n->next[x],s+char(x+97));
}
template<class V>
void Trie<V>::match(const string & str,Dictionary & dic,Node * n,string s) const
{   int x,len=s.length();
    if(str[len]=='.')
    {  for(x=0;x<26;x++)
            if(n->next[x]!=nullptr)
                match(str,dic,n->next[x],s+char(x+97)); 
    }
    else if(islower(str[len]))
    {   if(n->next[str[len]-97]!=nullptr)
            match(str,dic,n->next[str[len]-97],s+str[len]);
    } 
    else if(str[len]=='\0'&&n->value!=nullptr)
        dic.push_back(s);
}
template<class V>
int Trie<V>::getSize(Node * n) const
{   if(n==nullptr)
        return 0;
    return n->size;
}
template<class V>
void Trie<V>::destroyNode(Node * n)
{   int x;
    for(x=0;x<26;x++)
    {   if(n->next[x]!=nullptr)
        {   destroyNode(n->next[x]);
            delete n->next[x];
            n->next[x]=nullptr;
        } 
    }
    if(n->value!=nullptr)
    {   delete n->value;
        n->value=nullptr;
    }
}
template<class V>
string Trie<V>::floorExact(const string & str,Node * n,string cur) const
{   int x;
    string temp;
    if(cur.length()==str.length())
    {   if(n->value!=nullptr)
            return str;
        else
            return "";
    }
    else
    {   if(n->next[str[cur.length()]-97]!=nullptr&&(temp=floorExact(str,n->next[str[cur.length()]-97],cur+str[cur.length()])).length())
            return temp;
        else
        {   for(x=str[cur.length()]-98;x>=0;x--)
                if(n->next[x]!=nullptr&&(temp=floorMax(str,n->next[x],cur+char(x+97))).length())
                    return temp;
            if(n->value!=nullptr)
                return cur;
            else
                return "";
        }
    }
}
template<class V>
string Trie<V>::floorMax(const string & str,Node * n,string cur) const
{   int x;
    string temp;
    for(x=25;x>=0;x--)
        if(n->next[x]!=nullptr&&(temp=floorMax(str,n->next[x],cur+char(x+97))).length())
            return temp;
    if(n->value!=nullptr)
        return cur;
    else
        return "";
}
template<class V>
string Trie<V>::ceilExact(const string & str,Node * n,string cur) const
{   int x;
    string temp;
    if(cur.length()<str.length())
    {   if(n->next[str[cur.length()]-97]!=nullptr&&(temp=ceilExact(str,n->next[str[cur.length()]-97],cur+str[cur.length()])).length())
            return temp;
        else
        {   for(x=str[cur.length()]-96;x<26;x++)
                if(n->next[x]!=nullptr&&(temp=ceilMin(str,n->next[x],cur+char(x+97))).length())
                    return temp;
            return "";
        }
    }
    else 
    {   if(n->value!=nullptr)
            return cur;
        for(x=0;x<=25;x++)
            if(n->next[x]!=nullptr&&(temp=ceilMin(str,n->next[x],cur+char(x+97))).length())
                    return temp;
        return "";
    }
}
template<class V>
string Trie<V>::ceilMin(const string & str,Node * n,string cur) const
{   int x;
    string temp;
    if(n->value!=nullptr)
        return cur;
    for(x=0;x<=25;x++)
        if(n->next[x]!=nullptr&&(temp=ceilMin(str,n->next[x],cur+char(x+97))).length())
            return temp;
    return "";
}
template<class V>
Trie<V>::Trie()
{   root=new Node;
    root->size=0;
}
template<class V>
Trie<V>::~Trie()
{   clear();
    delete root;
}
template<class V>
bool Trie<V>::contains(const string & str) const
{   Node * ptr=root;
    int x;
    for(x=0;x<str.length();x++)
    {   if(ptr->next[str[x]-97]==nullptr)
            return 0;
        ptr=ptr->next[str[x]-97];
    }
    if(ptr->value==nullptr)
        return 0;
    else
        return 1;
}
template<class V>
V Trie<V>::operator[](const string & str) const
{   Node * ptr=root;
    int x;
    for(x=0;x<str.length();x++)
    {   if(ptr->next[str[x]-97]==nullptr)
            return 0;
        ptr=ptr->next[str[x]-97];
    }
    return *(ptr->value);
}
template<class V>
V & Trie<V>::operator[](const string & str)
{   Node * ptr=root;
    int x;
    for(x=0;x<str.length();x++)
    {   if(ptr->next[str[x]-97]==nullptr)
            return 0;
        ptr=ptr->next[str[x]-97];
    }
    return *(ptr->val);
}
template<class V>
Dictionary Trie<V>::allKeys(void) const
{   Dictionary dic;
    collect(dic,root,"");
    return dic;
}
template<class V>
Dictionary Trie<V>::keyMatch(const string & str) const
{   Dictionary dic;
    match(str,dic,root,"");
    return dic;
}
template<class V>
string Trie<V>::longestPrefix(const string & str) const
{   int x=0,i=0;
    Node * ptr=root;
    while(str[x]!='\0'&&ptr!=nullptr)
    {   x++;
        if(ptr->value!=nullptr)
            i=x;
        ptr=ptr->next[str[x-1]-97];
    }
    return str.substr(0,i-1);
}
template<class V>
int Trie<V>::rank(const string & str) const
{   int x,y,rk=0;
    Node * ptr=root; 
    for(x=0;x<str.length();x++)
    {   if(ptr->next[str[x]-97]==nullptr)
            return -1;
        if(ptr->value!=nullptr)
            rk++;
        for(y=0;y<str[x]-97;y++)
            rk+=getSize(ptr->next[y]);
        ptr=ptr->next[str[x]-97];
    }
    return rk;
}
template<class V>
string Trie<V>::select(int rk)
{   if(rk<0||rk>=root->size)
        return "";
    string str="";
    int x,count=0;
    Node * ptr=root;
    while(1)
    {   if(ptr->value!=nullptr)
        {   count++;
            if(count==rk+1)
                return str;
        }
        for(x=0;x<26;x++)   
            if(count+getSize(ptr->next[x])>rk)
            {   str+=char(x+97);
                ptr=ptr->next[x];
                break;
            }
            else
                count+=getSize(ptr->next[x]);
    }
}
#endif
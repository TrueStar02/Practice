#ifndef TRIPLEST_H_
#define TRIPLEST_H_  
#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
typedef vector<string> Dictionary;
template<class V>
class TripleST
{   private:
        class Node
        {   public:
                char ch;
                V * value;
                Node * left;
                Node * mid;
                Node * right;
                int size;
                Node():size(0)
                {   value=nullptr;
                    left=mid=right=nullptr;
                }
                Node(const V & val):size(1)
                {   value=new V(val);
                    left=mid=right=nullptr;
                }
        };
        Node * root;
        bool addKey(Node * n,const string & str,const V & val,int pos);
        bool delKey(Node * &n,const string & str,int pos);
        void delAdjust(Node * &n);
        void collect(Dictionary & dic,Node * n,string s) const;
        void match(const string & str,Dictionary & dic,Node * n,string s) const;
        int getSize(Node * n) const;
        string floorExact(const string & str,Node * n,string cur) const;
        string floorMax(const string & str,Node * n,string cur) const;
        string ceilExact(const string & str,Node * n,string cur)const;
        string ceilMin(const string & str,Node * n,string cur) const;
        void destroyNode(Node * n);
        void print(Node * n,int num)
        {   int y;
            if(n->left!=nullptr)
                print(n->left,num);
            for(y=0;y<num;y++)
                cout.put('-');
            cout<<n->ch<<" Num:"<<n->size;
            if(n->value!=nullptr)
                cout<<" Value:"<<n->value;
            cout<<endl;
            if(n->mid!=nullptr)
                print(n->mid,num+1);
            if(n->right!=nullptr)
                print(n->right,num);
        }
    public:
        TripleST(){root=nullptr;}
        void debug(void){if(root!=nullptr)print(root,0);}
        TripleST(const TripleST & tr)=delete;
        TripleST(TripleST && tr)=delete;
        ~TripleST(){clear();}
        TripleST & operator=(const TripleST & tr)=delete;
        TripleST & operator=(TripleST && tr)=delete;
        bool insert(const string & str,const V & val);
        bool erase(const string & str);
        bool contains(const string & str) const;
        V operator[](const string & str) const;
        V & operator[](const string & str); 
        Dictionary allKeys(void) const;
        Dictionary keyMatch(const string & str) const;
        string longestPrefix(const string & str) const;
        string floor(const string & str) const;
        string ceiling(const string & str) const;
        int rank(const string & str) const;
        string select(int rk);
        void clear();
};
template<class V>
bool TripleST<V>::addKey(Node * n,const string & str,const V & val,int pos)
{   bool i;
    if(str[pos]==n->ch)
    {   if(str[pos+1]=='\0')
        {   if(n->value==nullptr)
            {   n->value=new V(val);
                n->size++;
                return 1;
            }
            else
                return 0;
        }
        else 
        {   if(n->mid==nullptr)
            {   n->mid=new Node;
                n->mid->ch=str[pos+1];
            }
            i=addKey(n->mid,str,val,pos+1);
            n->size+=i;
            return i;
        }
    }
    else if(str[pos]<n->ch)
    {   if(n->left==nullptr)
        {   n->left=new Node;
            n->left->ch=str[pos];
        }
        i=addKey(n->left,str,val,pos);
        n->size+=i;
        return i;
    }
    else if(str[pos]>n->ch)
    {   if(n->right==nullptr)
        {   n->right=new Node;
            n->right->ch=str[pos];
        }
        i=addKey(n->right,str,val,pos);
        n->size+=i;
        return i;
    }
}
template<class V>
bool TripleST<V>::delKey(Node * &n,const string & str,int pos)
{   bool i;
    if(str[pos]==n->ch)
    {   if(pos+1==str.length())
        {   if(n->value!=nullptr)
            {   delete n->value;
                n->value=nullptr;
                n->size--;
                if(n->mid==nullptr)
                    delAdjust(n);
                return 1;
            }
            else
                return 0;
        }
        else
        {   if(n->mid!=nullptr)
            {   i=delKey(n->mid,str,pos+1);
                if(i&&n->mid==nullptr&&n->value==nullptr)
                    delAdjust(n);
                else if(n!=nullptr)
                    n->size-=i;
                return i;
            }
            else
                return 0;
        }

    }
    else if(str[pos]>n->ch)
    {   if(n->right!=nullptr)
        {   i=delKey(n->right,str,pos);
            n->size-=i;
            return i;
        }
        else
            return 0;
    }
    else
    {   if(n->left!=nullptr)
        {   i=delKey(n->left,str,pos);
            n->size-=i;
            return i;
        }
        else
            return 0;
    }
}
template<class V>
void TripleST<V>::delAdjust(Node * &n)
{   Node * temp,* parent;
    if(n->left==nullptr&&n->right==nullptr)
    {   delete n;
        n=nullptr;
    }
    else if(n->right==nullptr)
    {   temp=n;
        n=n->left;
        delete temp;
    }
    else if(n->left==nullptr)
    {   temp=n;
        n=n->right;
        delete temp;
    }
    else
    {   parent=n;
        temp=n->left;
        while(temp->right!=nullptr)
        {   parent=temp;
            temp=temp->right;
        }
        n->ch=temp->ch;
        n->value=temp->value;
        n->mid=temp->mid;
        temp->mid=nullptr;
        temp->value=nullptr;
        if(parent==n)
            delAdjust(n->left);
        else
            delAdjust(parent->right);
        if(n->left!=nullptr)
        {   temp=n->left;
            while(temp!=nullptr&&temp->right!=nullptr)
            {   temp->size-=getSize(n->mid);
                temp=temp->right;
            }
        }
        n->size--;
    }
}
template<class V>
void TripleST<V>::collect(Dictionary & dic,Node * n,string s) const
{   if(n->left!=nullptr)
        collect(dic,n->left,s);
    if(n->value!=nullptr)
        dic.push_back(s+(n->ch));
    if(n->mid!=nullptr)
        collect(dic,n->mid,s+(n->ch));
    if(n->right!=nullptr)
        collect(dic,n->right,s);
}
template<class V>
void TripleST<V>::match(const string & str,Dictionary & dic,Node * n,string s) const
{   int len=s.length();
    if(str[len]=='.')
    {   if(n->left!=nullptr)
            match(str,dic,n->left,s);
        if(n->value!=nullptr&&str[len+1]=='\0')
            dic.push_back(s+(n->ch));
        if(n->mid!=nullptr)
            match(str,dic,n->mid,s+(n->ch));
        if(n->right!=nullptr)
            match(str,dic,n->right,s);
    }
    else if(str[len]==n->ch)
    {   if(str[len+1]!='\0')
        {   if(n->mid!=nullptr)
                match(str,dic,n->mid,s+(n->ch));
        }
        else if(n->value!=nullptr)
            dic.push_back(s+(n->ch));
    }
    else if(str[len]<n->ch&&n->left!=nullptr)
        match(str,dic,n->left,s);
    else if(str[len]>n->ch&&n->right!=nullptr) 
        match(str,dic,n->right,s);
}
template<class V>
int TripleST<V>::getSize(Node * n) const
{   if(n==nullptr)
        return 0;
    return n->size;
}
template<class V>
string TripleST<V>::floorExact(const string & str,Node * n,string cur) const
{   string temp;
    if(n->ch==str[cur.length()])
    {   if(str.length()==cur.length()+1)
        {   if(n->value!=nullptr)
                return str;
            else if(n->left!=nullptr&&(temp=floorMax(str,n->left,cur)).length())
                return temp;
            else
                return "";
        }
        else if(n->mid!=nullptr&&(temp=floorExact(str,n->mid,cur+(n->ch))).length())
            return temp;
        else if(n->value!=nullptr)
            return cur+(n->ch);
        else if(n->left!=nullptr&&(temp=floorMax(str,n->left,cur)).length())
            return temp;
        else
            return "";          
    }
    else if(n->ch>str[cur.length()])
    {   if(n->left!=nullptr&&(temp=floorExact(str,n->left,cur)).length())
            return temp;
        else
            return "";
    }
    else
    {   if(n->right!=nullptr&&(temp=floorExact(str,n->right,cur)).length())
            return temp;
        else if(n->mid!=nullptr&&(temp=floorMax(str,n->mid,cur+(n->ch))).length())
            return temp;
        else if(n->value!=nullptr)
            return cur+(n->ch);
        else if(n->left!=nullptr&&(temp=floorMax(str,n->left,cur)).length())
            return temp;
        else
            return "";
    }
}
template<class V>
string TripleST<V>::floorMax(const string & str,Node * n,string cur) const
{   string temp;
    if(n->right!=nullptr&&(temp=floorMax(str,n->right,cur)).length())
        return temp;
    else if(n->mid!=nullptr&&(temp=floorMax(str,n->mid,cur+(n->ch))).length())
        return temp;
    else if(n->value!=nullptr)
        return cur;
    else if(n->left!=nullptr&&(temp=floorMax(str,n->left,cur)).length())
        return temp;
    else
        return "";
}
template<class V>
string TripleST<V>::ceilExact(const string & str,Node * n,string cur)const
{   string temp;
    if(str[cur.length()]==n->ch)
    {   if(cur.length()==str.length()-1)
        {   if(n->value!=nullptr)
                return str;
            else if(n->mid!=nullptr&&(temp=ceilExact(str,n->mid,cur+(n->ch))).length())
                return temp;
            else if(n->right!=nullptr&&(temp=ceilMin(str,n->right,cur)).length())
                return temp;
            else
                return "";
        }
        else
        {   if(n->mid!=nullptr&&(temp=ceilExact(str,n->mid,cur+(n->ch))).length())
                return temp;
            else if(n->right!=nullptr&&(temp=ceilMin(str,n->right,cur)).length())
                return temp;
            else
                return "";
        }
    }
    else if(str[cur.length()]>n->ch)
    {   if(n->right!=nullptr&&(temp=ceilExact(str,n->right,cur)).length())
            return temp;
        else
            return "";
    }
    else
    {   if(n->left!=nullptr&&(temp=ceilExact(str,n->left,cur)).length())
            return temp;
        else if(n->value!=nullptr)
            return cur+(n->ch);
        else if(n->mid!=nullptr&&(temp=ceilMin(str,n->mid,cur+(n->ch))).length())
            return temp;
        else if(n->right!=nullptr&&(temp=ceilMin(str,n->right,cur)).length())
            return temp;
        else
            return "";
    }
}
template<class V>
string TripleST<V>::ceilMin(const string & str,Node * n,string cur) const
{   string temp;
    if(n->left!=nullptr&&(temp=ceilMin(str,n->left,cur)).length())
        return temp;
    else if(n->value!=nullptr)
        return cur+(n->ch);
    else if(n->mid!=nullptr&&(temp=ceilMin(str,n->mid,cur+(n->ch))).length())
        return temp;
    else if(n->right!=nullptr&&(temp=ceilMin(str,n->right,cur)).length())
        return temp;
    else
        return "";
}
template<class V>
void TripleST<V>::destroyNode(Node * n)
{   if(n->value!=nullptr)
        delete n->value;
    if(n->left!=nullptr)
    {   destroyNode(n->left);
        delete n->left;
    }
    if(n->mid!=nullptr)
    {   destroyNode(n->mid);
        delete n->mid;
    }
    if(n->right!=nullptr)
    {   destroyNode(n->right);
        delete n->right;
    }
}
template<class V>
bool TripleST<V>::insert(const string & str,const V & val)
{   if(root==nullptr)
    {   root=new Node;
        root->ch=str[0];
    }
    return addKey(root,str,val,0);
}
template<class V>
bool TripleST<V>::erase(const string & str)
{   if(root!=nullptr)
        return delKey(root,str,0);
    else
        return 0;
}
template<class V>
bool TripleST<V>::contains(const string & str) const
{   if(root==nullptr)
        return 0;
    Node * ptr=root;
    int x;
    for(x=0;x<str.length();x++)
    {   while(ptr->ch!=str[x])
        {   if(ptr->ch>str[x])
            {   if(ptr->left!=nullptr)
                    ptr=ptr->left;
                else
                    return 0;
            }
            else
            {   if(ptr->right!=nullptr)
                    ptr=ptr->right;
                else
                    return 0; 
            }
        }
        if(x==str.length()-1)
        {   if(ptr->value!=nullptr)
                return 1;
            else
                return 0;
        }
        else   
        {   if(ptr->mid!=nullptr)
                ptr=ptr->mid;
            else
                return 0;
        }
    }
}
template<class V>
V TripleST<V>::operator[](const string & str) const
{   if(root==nullptr)
        return 0;
    if(root==nullptr)
        return 0;Node * ptr=root;
    int x;
    for(x=0;x<str.length();x++)
    {   while(ptr->ch!=str[x])
        {   if(ptr->ch>str[x])
            {   if(ptr->left!=nullptr)
                    ptr=ptr->left;
                else
                    return 0;
            }
            else
            {   if(ptr->right!=nullptr)
                    ptr=ptr->right;
                else
                    return 0; 

            }
        }
        if(x==str.length()-1)
        {   if(ptr->value!=nullptr)
                return *(ptr->value);
            else
                return 0;
        }
        else   
        {   if(ptr->mid!=nullptr)
                ptr=ptr->mid;
            else
                return 0;
        }
    }
}
template<class V>
V & TripleST<V>::operator[](const string & str)
{   if(root==nullptr)
        return 0;
    Node * ptr=root;
    int x;
    for(x=0;x<str.length();x++)
    {   while(ptr->ch!=str[x])
        {   if(ptr->ch>str[x])
            {   if(ptr->left!=nullptr)
                    ptr=ptr->left;
                else
                    return 0;
            }
            else
            {   if(ptr->right!=nullptr)
                    ptr=ptr->right;
                else
                    return 0; 

            }
        }
        if(x==str.length()-1)
        {   if(ptr->value!=nullptr)
                return *(ptr->value);
            else
                return 0;
        }
        else   
        {   if(ptr->mid!=nullptr)
                ptr=ptr->mid;
            else
                return 0;
        }
    }
}
template<class V>
Dictionary TripleST<V>::allKeys(void) const
{   Dictionary dic;
    if(root!=nullptr)
        collect(dic,root,"");
    return dic;
}
template<class V>
Dictionary TripleST<V>::keyMatch(const string & str) const
{   Dictionary dic;
    if(root!=nullptr)
        match(str,dic,root,"");
    return dic;
}
template<class V>
string TripleST<V>::longestPrefix(const string & str) const
{   if(root==nullptr)
        return "";
    Node * ptr=root;
    int x=0,i=0;
    while(str[x]!='\0'&&ptr!=nullptr)
    {   if(ptr->ch==str[x])
        {   x++;
            if(ptr->value!=nullptr)
                i=x;
            ptr=ptr->mid;
        }
        else if(ptr->ch>str[x])
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return str.substr(0,i);
}
template<class V>
string TripleST<V>::floor(const string & str) const
{   if(root!=nullptr)
        return floorExact(str,root,"");
    else
        return "";
}
template<class V>
string TripleST<V>::ceiling(const string & str) const
{   if(root!=nullptr)
        return ceilExact(str,root,"");
    else
        return "";
}
template<class V>
int TripleST<V>::rank(const string & str) const
{   if(root==nullptr)
        return 0;
    int x,y,rk=0;
    Node * ptr=root;
    for(x=0;x<str.length();x++)
    {   if(ptr->ch>str[x])
        {   if(ptr->left==nullptr) 
                return -1;
            else
                ptr=ptr->left;
        }
        else if(ptr->ch==str[x])
        {   if(str[x+1]=='\0')
            {   if(ptr->value==nullptr)
                    return -1;
                else
                    return rk+getSize(ptr->left);
            }
            else
            {   if(ptr->value!=nullptr)
                    rk++;
                rk+=getSize(ptr->left);
                ptr=ptr->mid;
            }
        }
        else
        {   if(ptr->right==nullptr) 
                return -1;
            else
            {   if(ptr->value!=nullptr)
                    rk++;
                rk+=getSize(ptr->left);
                rk+=getSize(ptr->mid);
                ptr=ptr->right;
            }
        }
    }
}
template<class V>
string TripleST<V>::select(int rk)
{   if(rk<0||rk>=getSize(root))
        return "";
    Node * ptr=root;
    int count=0;
    string str="";
    while(1)
    {   if(count+getSize(ptr->left)>rk)
            ptr=ptr->left;
        else
        {   count+=getSize(ptr->left);
            if(ptr->value!=nullptr)
            {   count++;
                if(rk==count-1)
                    return str+(ptr->ch);
            }
            if(count+getSize(ptr->mid)>rk)
            {   str+=ptr->ch;
                ptr=ptr->mid;
            }
            else
            {   count+=getSize(ptr->mid);
                ptr=ptr->right;
            }
        }
    }
}
template<class V>
void TripleST<V>::clear()
{   if(root!=nullptr)
    {   destroyNode(root);
        delete root;
        root=nullptr;
    }
}
#endif
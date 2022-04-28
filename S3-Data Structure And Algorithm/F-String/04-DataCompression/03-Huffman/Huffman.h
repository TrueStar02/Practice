#ifndef HUFFMAN_H_
#define HUFFMAN_H_
#include<iostream>
#include<queue>
using namespace std;
class Node
{   public:
        bool isLeaf;
        char ch;
        int freq;
        Node * left;
        Node * right;
        Node(bool i,char c,int f,Node * l=nullptr,Node * r=nullptr):isLeaf(i),ch(c),freq(f),left(l),right(r){}
};
class handle
{   public:
        handle(){}
        bool operator()(Node * n1,Node * n2) const
        {   if(n1->freq>n2->freq)
                return 1;
            return 0;    
        }
};
class Huffman
{   private:
        Node * root;
        string * ori;
        void makeTable(string * table,Node * n,string str);
        void write(Node * n,ofstream & fout);
        string toBinary(char ch);
        void createByInput(const string & str,int & index,Node * &n);
        void clear(Node * n);
    public:
        Huffman(int * fre);
        Huffman(const string & instr);
        ~Huffman();
        string * compressTable(void);
        void writeTree(ofstream & fout){if(root!=nullptr)write(root,fout);}
        string origin(void);
};
void Huffman::makeTable(string * table,Node * n,string str)
{   if(n->isLeaf)
        table[n->ch]=str;
    else
    {   makeTable(table,n->left,str+'0');
        makeTable(table,n->right,str+'1');
    }
}
void Huffman::write(Node * n,ofstream & fout)
{   if(n->isLeaf)
        fout<<1<<toBinary(n->ch);
    else
    {   fout<<0;
        write(n->left,fout);
        write(n->right,fout);
    }
}
string Huffman::toBinary(char ch)
{   char str[9];
    str[8]='\0';
    int x;
    for(x=7;x>=0;x--)
    {   str[x]=(ch&1)+48;
        ch>>=1;
    }
    return string(str);
}
void Huffman::createByInput(const string & str,int & index,Node * &n)
{   if(str[index]=='1')
    {   int x;
        char ch=0;
        index++;
        for(x=7;x>=0;x--,index++)
            ch+=((str[index]-48)<<x);
        n=new Node(1,ch,0);
    }
    else
    {   n=new Node(0,0,0);
        index++;
        createByInput(str,index,n->left);
        createByInput(str,index,n->right);
    }
}
void Huffman::clear(Node * n)
{   if(!(n->isLeaf))
    {   clear(n->left);
        clear(n->right);
    }
    delete n;
}
Huffman::Huffman(int * fre):ori(nullptr)
{   priority_queue<Node *,vector<Node *>,handle> pq;
    Node * n1,* n2;
    int x;
    for(x=0;x<128;x++)
        if(fre[x])
            pq.push(new Node(1,x,fre[x]));
    while(pq.size()>1)
    {   n1=pq.top();
        pq.pop();
        n2=pq.top();
        pq.pop();
        pq.push(new Node(0,0,n1->freq+n2->freq,n1,n2));
    }
    if(pq.size())
    {   root=pq.top();
        pq.pop();
    }
    else
        root=nullptr;
}
Huffman::Huffman(const string & instr)
{   int index=0;
    createByInput(instr,index,root);
    ori=new string;
    Node * temp=root;
    while(instr[index]!='\0')
    {   if(instr[index]=='0')
            temp=temp->left;
        else
            temp=temp->right;
        if(temp->isLeaf)
        {   (*ori)+=temp->ch;
            temp=root;
        }
        index++;
    }
}
Huffman::~Huffman()
{   if(ori!=nullptr)
        delete ori;
    if(root!=nullptr)
        clear(root);
}
string * Huffman::compressTable(void)
{   string * table=new string[128];
    if(root!=nullptr)
        makeTable(table,root,"");
    return table;
}
string Huffman::origin(void)
{   if(ori==nullptr)
        return "";
    else
        return *ori;
}
#endif
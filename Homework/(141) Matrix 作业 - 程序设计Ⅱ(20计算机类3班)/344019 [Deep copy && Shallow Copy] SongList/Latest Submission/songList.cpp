#include "songList.h"
#include<iostream>
using namespace std;
SongList::SongList(const std::string _owner, unsigned int _size, unsigned int _capacity, std::string *_songs):size(_size),capacity(_capacity),owner(_owner)
{   songs=new string[2500];
    for(int x=0;x<size;x++)
        songs[x]=_songs[x];
}

SongList::SongList(const SongList &s):size(s.size),capacity(s.capacity),owner(s.owner)
{   songs=new string[2500];
    for(int x=0;x<size;x++)
        songs[x]=s.songs[x];
}

    // 添加歌曲，请考虑去重的情况（如果歌曲已经存在则不添加）、歌单已经满了需要扩容的情况，扩容方案自选
    // 扩容方案1：原地扩容，C语言中有个realloc函数可以实现
    // 扩容方案2：重新开辟一个更大容量songs歌曲列表，并将当前的数据迁移过去
void SongList::addSong(const std::string &song)
{   int x;
    for(x=0;x<size;x++)
        if(song==songs[x])return;
    songs[size]=song;
    size++;
    if(size>capacity)
        capacity++;

}

    // 删除指定歌曲，歌曲不存在则无动作
void SongList::removeSong(const std::string &song)
{   int x;
    for(x=0;x<size;x++)
        if(song==songs[x])
            break;
    if(x!=size)
    {   for(;x<size-1;x++)
            songs[x]=songs[x+1];
        size--;
    }

}

    // 清空歌曲
void SongList::clearSong(){size=0;}

SongList & SongList::operator=(const SongList &s)
{   if(this==&s)
        return *this;
    size=s.size;
    capacity=s.capacity;
    owner=s.owner;
    for(int x=0;x<size;x++)
        songs[x]=s.songs[x];
    return *this;

}

ostream & operator<<(ostream &os, const SongList &s)
{   if(s.size==0)
        cout<<s.owner<<"'s SongList is Empty.\n";
    else
    {   cout<<"owner:"<<s.owner<<endl;
        cout<<"Songs:"<<endl;
        for(int x=0;x<s.size;x++)
            cout<<s.songs[x]<<endl;
    }
    return os;
}

SongList::~SongList(){delete [] songs;}
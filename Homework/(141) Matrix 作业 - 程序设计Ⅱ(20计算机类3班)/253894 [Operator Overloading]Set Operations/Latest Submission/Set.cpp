  // Create an empty set.
  #include "Set.hpp"
    Set::Set()
    {size=0;}
    // Create an set with some element.
    Set::Set(int* m, int s)
    {   size=s;
        int x,y;
        members[0]=m[0];
        for(x=1;x<s;x++)
        {   for(y=x-1;y>=0;y--)
                if(m[x]<members[y])
                    members[y+1]=members[y];
                else
                    break;
            members[y+1]=m[x];
        }
        
    }
    // Copy Constructor
    Set::Set(Set const &s)
    {   size=s.size;
        int x;
        for(x=0;x<size;x++)
            members[x]=s.members[x];
    }
    // append a element to set.
    // If element in the set, return false.
    // Or insert in set and return true.
    bool Set::append(int e)
    {   if(isInSet(e))return 0;
        size++;
        int y;
         for(y=size-2;y>=0;y--)
                if(e<members[y])
                    members[y+1]=members[y];
                else
                    break;
            members[y+1]=e;
            return 1;
    }
    
    // remove a element by its value from set.
    // If element in the set, then remove it and return true.
    // Or return false.
    bool Set::remove(int e)
    {   for(int x=0;x<size;x++)
            if(members[x]==e)
            {   for(int y=x+1;y<size;y++)
                    members[y-1]=members[y];
                size--;
                return 1;
            }
            else if(members[x]>e)
                return 0;
        return 0;
    }
    // return true if the set is empty, or return false.
    bool Set::isEmptySet(){return !size;}
    
    // return true if the element e is in the set, or return false.
    bool Set::isInSet(int e)
    {
        for(int x=0;x<size;x++)
             if(members[x]==e)
            {   
                return 1;
            }
        return 0;
    }
    // & is intersection of two set
    Set Set::operator&(const Set &s)
    {   Set temp;
        int x,y=0;
        for(x=0;x<size;x++)
        {   while(s.members[y]<members[x]&&y<s.size)
                y++;
            if(y==s.size)
                break;
            if(s.members[y]==members[x])
            {   y++;
                temp.append(members[x]);
            }
        }
        return temp;
    }
    // | is union of two set
    Set Set::operator|(const Set &s)
    {   Set temp;
        int x;
        for(x=0;x<size;x++)
            temp.append(members[x]);
        for(x=0;x<s.size;x++)
            temp.append(s.members[x]);
        return temp;
    }
    // A - B is the complement of B with respect to A
    Set Set::operator-(const Set &s)
    {   Set temp;
        int x,y=0;
        for(x=0;x<size;x++)
        {   while(s.members[y]<members[x]&&y<s.size-1)
                y++;
             
            if(s.members[y]==members[x])
               y++;
            else
               temp.append(members[x]); 
           
        }
        return temp;
    }
    // A + B is their symmetric difference. A + B = (A - B) | (B - A)
    Set Set::operator+(const Set &s)
    {    Set temp;
        int x,y=0;
        for(x=0;x<size;x++)
        {   while(s.members[y]<members[x]&&y<s.size-1)
                y++;
                
            if(s.members[y]==members[x])
               y++;
            else
               temp.append(members[x]); 
           
        }
        y=0;
         for(x=0;x<s.size;x++)
        {   while(members[y]<s.members[x]&&y<size-1)
                y++;
                 
            if(members[y]==s.members[x])
               y++;
            else
               temp.append(s.members[x]); 
           
        }
        return temp;
    }
    // return set.
    int* Set::getMembers()
    {return members;}
    
    // return size of set.
    int Set::getSize(){return size;}
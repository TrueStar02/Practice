#include "IntegerSet.h"
IntegerSet::IntegerSet(int s[], int l)
{    for(int x=0;x<=100;x++)
            set[x]=0;
    for(int x=0;x<l;x++)
    {
         if(validEntry(s[x]))
              set[s[x]]=1;
              else
              cout<<"Invalid insert attempted!\n";
    }

}
          IntegerSet IntegerSet::unionOfSets(const IntegerSet&s)
          {   IntegerSet ns;
              for(int x=0;x<=100;x++)
              ns.set[x]=set[x]|s.set[x];
              return ns;
          }
          IntegerSet IntegerSet::intersectionOfSets(const IntegerSet&s)
          {     IntegerSet ns;
              for(int x=0;x<=100;x++)
              ns.set[x]=set[x]&s.set[x];
              return ns;
          }
          void IntegerSet::emptySet()
          {
              for(int x=0;x<=100;x++)
              set[x]=0;
          } // set all elements of set to
          void IntegerSet::insertElement(int element)
          {    if(validEntry(element))
              set[element]=1;
              else
              cout<<"Invalid insert attempted\n";
          }
          void IntegerSet::deleteElement(int element)
          { if(validEntry(element))
              set[element]=0;
              else
              cout<<"Invalid delete attempted\n";
          }
           bool IntegerSet::isEqualTo(const IntegerSet&s) const
           {
               for(int x=0;x<=100;x++)
                if(set[x]!=s.set[x])
                    return 0;
                return 1;
           }
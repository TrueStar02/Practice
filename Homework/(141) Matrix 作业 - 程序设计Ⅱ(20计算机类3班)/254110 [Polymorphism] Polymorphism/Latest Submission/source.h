class SortByPrice : public SortInterface
{
public:
  virtual void DoSort(TaoBaoItem item[], int size)
  {    int x,y;
        TaoBaoItem temp;
      for(x=0;x<size-1;x++)
      for(y=x+1;y<size;y++)
        if(item[x].price<item[y].price)
        {   temp=item[x];
            item[x]=item[y];
            item[y]=temp;
        }

  }
};

class SortBySales : public SortInterface 
{
public:
virtual void DoSort(TaoBaoItem item[], int size)
{    int x,y;
        TaoBaoItem temp;
      for(x=0;x<size-1;x++)
      for(y=x+1;y<size;y++)
        if(item[x].volume_of_sales<item[y].volume_of_sales)
        {   temp=item[x];
            item[x]=item[y];
            item[y]=temp;
        }

  }
};

class TaoBao 
{private:
  SortInterface *strategy_;
 public:
  TaoBao(SortInterface* s){strategy_=s;}

  void SetSortStrategy(SortInterface* s){strategy_=s;}

  // Use current strategy_ to do the sort.
  void sort(TaoBaoItem item[], int size){strategy_->DoSort(item,size);}

 
};
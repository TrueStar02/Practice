#ifndef TRIPLEMERGESORT_H_
#define TRIPLEMERGESORT_H_
class TripleMergeSort
{	private:
		int * temp;
		void TMSort(int * arr,int beg,int end);
		void TMerge(int * arr,int beg,int t1,int t2,int end);
		void InsSrt(int * arr,int size);
	public:
		void operator()(int * arr,int size);		
};
void TripleMergeSort::TMSort(int * arr,int beg,int end)
{	if(end-beg>14)
	{	int t1=beg+(end-beg)/3;
		int t2=beg+2*(end-beg)/3;
		TMSort(arr,beg,t1);
		TMSort(arr,t1+1,t2);
		TMSort(arr,t2+1,end);
		TMerge(arr,beg,t1,t2,end);
	}
	else if(beg<end)
		InsSrt(arr+beg,end-beg+1);
}
void TripleMergeSort::TMerge(int * arr,int beg,int t1,int t2,int end)
{	int x,i0=beg,i1=t1+1,i2=t2+1;
	if(arr[t1]<=arr[t1+1]&&arr[t2]<=arr[t2+1])
		return; 
	for(x=beg;x<=end;x++)
	{	if(i0>t1)
		{	if(i1>t2)
			{	arr[x]=temp[i2];
				i2++;
			}
			else if(i2>end)
			{	arr[x]=temp[i1];
				i1++;
			}
			else if(temp[i1]>temp[i2])
			{	arr[x]=temp[i2];
				i2++;
			}
			else
			{	arr[x]=temp[i1];
				i1++;
			}
		}
		else if(i1>t2)
		{	if(i2>end)
			{	arr[x]=temp[i0];
				i0++;
			}
			else if(temp[i0]>temp[i2])
			{	arr[x]=temp[i2];
				i2++;
			}
			else
			{	arr[x]=temp[i0];
				i0++;
			}
		}
		else if(i2>end)
		{	if(temp[i0]>temp[i1])
			{	arr[x]=temp[i1];
				i1++;
			}
			else
			{	arr[x]=temp[i0];
				i0++;
			}
		}
		else if(temp[i0]<=temp[i1]&&temp[i0]<=temp[i2])
		{	arr[x]=temp[i0];
			i0++;
		}
		else if(temp[i1]<=temp[i0]&&temp[i1]<=temp[i2])
		{	arr[x]=temp[i1];
			i1++;
		}
		else
		{	arr[x]=temp[i2];
			i2++;
		}
	}
}
void TripleMergeSort::InsSrt(int * arr,int size)
{	int x,y,temp,index;
	for(x=1;x<size;x++)
	{	temp=arr[x];
		for(y=x-1;y>=0;y--)
			if(arr[y]>temp)
			 	arr[y+1]=arr[y];
			 else
			 {	arr[y+1]=temp;
			 	break;
			 }
		if(y==-1)
		 	arr[0]=temp;
	}
}
void TripleMergeSort::operator()(int * arr,int size)
{	temp=new int[size];
	TMSort(arr,0,size-1);
	delete [] temp;
}
#endif

#ifndef HEAPSORT_H_
#define HEAPSORT_H_
class HeapSort
{	private:
		void Sink(int * arr,int beg,int end);
	public:
		void operator()(int * arr,int size);
};
void HeapSort::Sink(int * arr,int beg,int end)
{	int x;
	arr[0]=arr[beg];
	for(x=beg*2;x<=end;x*=2)
	{	if(x<end&&arr[x]<arr[x+1])
			x++;
		if(arr[0]>=arr[x])
			break;
		arr[beg]=arr[x];
		beg=x;
	}
	arr[beg]=arr[0];
}
void HeapSort::operator()(int * arr,int size)
{	int x;
	for(x=size/2;x>=1;x--)
		Sink(arr,x,size);
	for(x=size;x>1;x--)
	{	arr[0]=arr[1];
		arr[1]=arr[x];
		arr[x]=arr[0];
		Sink(arr,1,x-1);
	}
}
#endif

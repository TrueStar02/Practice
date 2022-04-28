#include<iostream>
using namespace std;
int Partition(int * arr,int beg,int end,int key);
int InsSrt3(int * arr,int size);
int Finding(int * arr,int k,int size);
int main()
{	int x,arr[12]={8,6,11,3,5,12,1,9,10,2,4,7};
	for(x=0;x<12;x++)
		cout<<Finding(arr,x,12)<<"\n";
	cout<<endl;
	return 0;
}
int Finding(int * arr,int k,int size)
{	int low=0,high=size-1,pivot,cur,group,i,key;
	int * mid;
	while(low<high)
	{	group=(high-low+1)/5;
		if((high-low+1)%5)
			group++;
		mid=new int[group];
		i=0;
		cur=low;
		while(cur<=high)
		{	
			mid[i]=InsSrt3(arr+cur,(high-cur<5)?(high-cur+1):5);
			//cout<<mid[i]<<" ";
			i++;
			cur+=5;
			
		}
		//cout<<endl;
		//for(int j=0;j<size;j++)
		//	cout<<arr[j]<<" ";
		//cout<<endl;
		if(group%2)
        	key=Finding(mid,group/2,group);
		else
			key=Finding(mid,group/2-1,group);
        pivot=Partition(arr,low,high,key);
		//cout<<key<<" "<<pivot<<"\n";
		if(pivot==k)
			return arr[pivot];
		else if(pivot>k)
			high=pivot-1;
		else
			low=pivot+1;
		delete mid;
	}
	return arr[high];
}
int Partition(int * arr,int beg,int end,int key)
{	int x,temp;
	for(x=beg;x<=end;x++)
		if(arr[x]==key)
			break;
	temp=arr[x];
	arr[x]=arr[beg];
	arr[beg]=temp;
	while(beg<end)
	{	while(beg<end&&arr[end]>=key)
			end--;
		arr[beg]=arr[end];
		while(beg<end&&arr[beg]<=key)
			beg++;
		arr[end]=arr[beg];
	}
	arr[beg]=key;
	return beg;
}
int InsSrt3(int * arr,int size)
{	int x,y,temp,index;
	for(x=1;x<size;x++)
	{	temp=arr[x];
		for(y=x-1;y>=0;y--)
			if(arr[y]>temp)
			 	arr[y+1]=arr[y];
			 else
			 	break;
		arr[y+1]=temp;
	}
	if(size%2)
		return arr[size/2];
	else
		return arr[size/2-1];
}


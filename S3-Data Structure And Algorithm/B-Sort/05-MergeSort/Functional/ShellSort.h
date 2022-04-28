#ifndef SHELLSORT_H_
#define SHELLSORT_H_
const int list1[]={1,4,13,40,121,364,1093,3280,9841,29524,88573,265720,797161,2391484,7174453,21523360,64570081,193710244};
const int list2[]={1,8,23,77,281,1073,4193,16577,65921,262913,1050113,4197377,16783361,67121153};
void ShellSrt1(int *arr,int size)
{	int jumpindex,x,y,temp;
	for(jumpindex=0;list1[jumpindex+1]<size;jumpindex++)
		continue;
	while(jumpindex>=0)
	{	for(x=0;x<size;x++)
			for(y=x;y>=list1[jumpindex]&&arr[y]<arr[y-list1[jumpindex]];y-=list1[jumpindex])
			{	temp=arr[y-list1[jumpindex]];
				arr[y-list1[jumpindex]]=arr[y];
				arr[y]=temp;
			}
		jumpindex--;
	}
}
void ShellSrt2(int *arr,int size)
{	int jumpindex,x,y,temp;
	//bool flag;
	for(jumpindex=0;list1[jumpindex+1]<size;jumpindex++)
		continue;
	while(jumpindex>=0)
	{	for(x=1;x<size;x++)
		{	temp=arr[x];
			for(y=x-list1[jumpindex];y>=0;y-=list1[jumpindex])
			{	if(arr[y]>temp)
					arr[y+list1[jumpindex]]=arr[y];
				else
				{	arr[y+list1[jumpindex]]=temp;
					break;
				}
			}
			if(y<0)
				arr[y+list1[jumpindex]]=temp;		
		}	
		jumpindex--;
	}
}
#endif

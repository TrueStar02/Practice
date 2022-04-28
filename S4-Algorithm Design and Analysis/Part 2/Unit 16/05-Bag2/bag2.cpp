#include<iostream>
using namespace std;
typedef pair<double,double> Thing;//1-value 2-amount
int Partition(Thing * arr,int beg,int end);
double Medium(Thing * arr,int beg,int end);
int main()
{   int n,x;
    double capacity;
    cin>>n>>capacity;
    Thing arr[n];
    for(x=0;x<n;x++)
        cin>>arr[x].first>>arr[x].second;
    int beg=0,end=n-1;
    Thing temp;
    double mid,sigma=0,pre_sigma;
    int index,pivot;
    for(x=0;x<n;x++)
        sigma+=arr[x].second;
    if(sigma<capacity+1e-6)
        index=n;
    else
    {   sigma=0;
        while(1)
        {   pivot=Partition(arr,beg,end);
            mid=arr[pivot].first;
            //mid=Medium(arr,beg,end);
            pre_sigma=sigma;
            index=-1;
            for(x=beg;x<=end;x++)
            {   if(arr[x].first>mid)
                    sigma+=arr[x].second;
                else if(arr[x].first==mid)
                {   index=x;
                    break;
                }
            }
            if(sigma<capacity+1e-6)
            {   if(sigma+arr[index].second>capacity-1e-6)
                    break;
                else
                    beg=index+1;
            }
            else
            {   end=index-1;
                sigma=pre_sigma;
            }

        }
    }
    
    double tot_value=0;
    for(x=0;x<index;x++)
        tot_value+=arr[x].first*arr[x].second;
    if(index!=n)
        tot_value+=arr[index].first*(capacity-sigma);
    cout<<tot_value<<endl;
    return 0;
}
int Partition(Thing * arr,int beg,int end)
{   
    Thing key,temp;
	if(arr[beg].first>arr[end].first)
	{	temp=arr[beg];
		arr[beg]=arr[end];
		arr[end]=temp;
	}
	if(arr[beg+1].first>arr[end].first)
	{	temp=arr[beg+1];
		arr[beg+1]=arr[end];
		arr[end]=temp;
	}
	if(arr[beg+1].first>arr[beg].first)
	{	temp=arr[beg+1];
		arr[beg+1]=arr[beg];
		arr[beg]=temp;
	}
	key=arr[beg];
	while(beg<end)
	{	while(beg<end&&arr[end].first<=key.first)
			end--;
		arr[beg]=arr[end];
		while(beg<end&&arr[beg].first>=key.first)
			beg++;
		arr[end]=arr[beg];
	}
	arr[beg]=key;
	return beg;
}  
/*double Medium(Thing * arr,int beg,int end)
{   int pivot=Partition(arr,beg,end);
    while(pivot!=(beg+end)/2)
    {   if(pivot>(beg+end)/2)
            pivot=Partition(arr,beg,pivot-1);
        else
            pivot=Partition(arr,pivot+1,end);
    }
    return arr[pivot].first;
}*/
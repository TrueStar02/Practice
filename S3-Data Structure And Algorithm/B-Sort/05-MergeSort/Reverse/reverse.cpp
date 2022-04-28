#include<iostream>
using namespace std;
class InverseNumber
{   private:
        int count;
        int * aux;
        int * arr;
        int size;
        void MergeSort(int beg,int end)
        {   if(beg<end)
            {   int mid=(beg+end)/2;
                MergeSort(beg,mid);
                MergeSort(mid+1,end);
                Merge(beg,mid,end);
            }
        }
        void Merge(int beg,int mid,int end)
        {   int x,left=beg,right=mid+1;
            for(x=beg;x<=end;x++)
                aux[x]=arr[x];
            for(x=beg;x<=end;x++)
            {   if(left>mid)
                {   
                    arr[x]=aux[right];
                    right++;
                }
                else if(right>end)
                {   arr[x]=aux[left];
                    left++;
                }
                else if(aux[left]<aux[right])
                {   arr[x]=aux[left];
                    left++;
                }
                else
                {   count+=mid+1-left;
                    arr[x]=aux[right];
                    right++;
                }
            }

        }
    public:
        int operator()(int * a,int n)
        {   size=n;
            arr=a;
            count=0;
            aux=new int[n];
            MergeSort(0,n-1);
            delete aux;
            return count;
        };
};
int main()
{   ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n,x;
    cin>>n;
    int arr[n];
    for(x=0;x<n;x++)
        cin>>arr[x];
    InverseNumber i;
    cout<<i(arr,n)<<'\n';
    //for(x=0;x<n;x++)
    //    cout<<arr[x]<<" ";
    return 0;
}
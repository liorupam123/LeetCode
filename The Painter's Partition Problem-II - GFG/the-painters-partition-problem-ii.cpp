// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
bool isPossibleTime(int arr[],int n,int k,long long mid)
   {
       int painter=1;
       long long sum=arr[0];
       for(long long i=1;i<n;i++)
       {
           sum+=arr[i];
           if(sum>mid)
           {
               painter++;
               sum=arr[i];
           }
           if(painter>k || arr[i]>mid)
           {
               return false;
           }
           
       }
       return true;
   }
    long long minTime(int arr[], int n, int k)
    {
        // code here
       // return minimum time
       if(n==1)
       {
           return arr[0];
       }
      
       long long low=0;
       long long high=0;
       long long sum=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]>low)
           {
               low=arr[i];
           }
           sum+=arr[i];
       }
       high=sum;
       if(k==n)
       {
           return low;
       }
       long long res=0;
       while(low<=high)
       {
           long long mid=low+(high-low)/2;
           if(isPossibleTime(arr,n,k,mid))
           {
               res=mid;
               high=mid-1;
           }
           else
           {
               low=mid+1;
           }
       }
       return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends
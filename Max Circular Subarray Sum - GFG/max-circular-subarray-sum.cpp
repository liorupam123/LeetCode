// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int a[], int n){
        
        // your code here
        int sum1=0,sum=0;
     int ans1=INT_MIN;
     if(n==1)
     return a[0];
     for(int i=0;i<n;i++)
     {
         sum+=a[i];
         sum1+=a[i];
         ans1=max(sum1,ans1);
         if(sum1<0)
         sum1=0;
         
     }
     int sum2=0;
     int ans2=INT_MAX;
     for(int i=0;i<n;i++)
     {
         sum2+=a[i];
         ans2=min(sum2,ans2);
         if(sum2>0)
         sum2=0;
     }
    
     ans2=sum-ans2;
    if(ans2==0)
    return ans1;
    
     return max(ans1,ans2);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
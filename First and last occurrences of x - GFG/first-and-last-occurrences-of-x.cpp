// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int low=0,high=n-1;
int left=-1,right=-1;
while(low<=high){
       int mid = (low+high)/2;
       
       if(arr[mid]==x){
           left=mid-1;right=mid+1;
           while(left>=low && arr[left]==x){
               left--;
           }
           left = left+1;
           while(right<=high && arr[right]==x){
               right++;
           }
           right = right-1;
           break;
       }
       
       if(x<arr[mid]){
           high=mid-1;
       }
       else if(x>arr[mid]){
           low=mid+1;
       }
   }
   vector<int> ans;
   ans.push_back(left);
   ans.push_back(right);
   
   return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
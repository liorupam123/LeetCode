// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int xorCal(int k){
        // code here
         if(k==1)return 2;
       int ans=-1;
       int x=k^(k+1);
       if(x==2*k+1){
           ans=k>>1;
       }
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        
        Solution ob;
        cout<<ob.xorCal(k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
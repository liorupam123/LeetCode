// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    int kknapSack(int W, int wt[], int val[], int n,vector<vector<int>>&dp){
       if(n<=0)return 0;
       if(W<=0)return 0;
       if(W<wt[n-1]) return dp[n][W]=kknapSack(W,wt,val,n-1,dp);
       if(dp[n][W]!=-1)return dp[n][W];
       dp[n][W] = max(kknapSack(W,wt,val,n-1,dp),val[n-1]+kknapSack(W-wt[n-1],wt,val,n-1,dp));
       return dp[n][W];
   }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return kknapSack(W,wt,val,n,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
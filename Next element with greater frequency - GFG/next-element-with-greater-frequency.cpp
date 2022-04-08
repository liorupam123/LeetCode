// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        vector<int>ans(n),suf(n);
   ans[n-1]=-1;
   map<int,int>freq;
   for(int i=0;i<n;i++)freq[arr[i]]++;
  stack<int>st;
  st.push(arr[n-1]);
  for(int i=n-2;i>=0;i--){
      ans[i]=-1;
      while(!st.empty()){
          if(freq[st.top()]>freq[arr[i]]){ans[i]=st.top();break;}
          st.pop();
      }
    st.push(arr[i]);  
  }
  return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string s, int n) {
        // code here
        int arr[]={6,2,5,5,4,5,6,3,7,5};
        long long int ans=0;
    for(int i=0;i<n;i++)
    ans+=arr[s[i]-'0'];
    ans=ans-2*n;
    string res="";
    for(int i=0;i<n;i++)
    {
        if(ans+2>=6)
        {
            res+="0";
            ans=ans-4;
        }
        else
        res+="1";
    }
    int k=n-1;
    while(ans>0)
    {
        if(ans+2>=7)
        {
            res[k]='8';
            ans=ans-5;
            k--;
            
        }
        else if(ans+2>=5)
        {
            res[k]='2';
            ans=ans-3;
            k--;
        }
        else if(ans+2>=4)
        {
            res[k]='4';
            ans=ans-2;
            k--;
        }
        else
        {
            res[k]='7';
            ans=ans-1;
            k--;
        }
        
    }
    return res;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
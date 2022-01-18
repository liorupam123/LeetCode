// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cuttingrod(int price[],int n,int index,unordered_map<string,int>&mp){
        if(n==0)    return 0;
        if(index>=n)    return 0;
        int cut = 0;
        string currentKey = to_string(index) + "_" + to_string(n);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }

        if(index+1<=n){
            cut = price[index] + cuttingrod(price,n-(index+1),index,mp);
        }
        int notcut = cuttingrod(price,n,index+1,mp);
        mp[currentKey] = max(cut,notcut);
        return mp[currentKey];
    }
    int cutRod(int price[], int n) {
        //code here
        unordered_map<string,int> mp;
        return cuttingrod(price,n,0,mp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
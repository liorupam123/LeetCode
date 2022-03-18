// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int a[], int n, int k) {
        // code here
         sort(a, a+n);
        vector<int> pa(n+1, 0);
        
        for(int i=1; i<=n; i++)
            pa[i] = pa[i-1]+a[i-1];
            
        int res = 1e9;
        for(int i=0; i<n; i++) {
            int j = upper_bound(a,a+n,a[i]+k)-a;
            res = min(res, pa[i]+(pa[n]-pa[j]-(n-j)*(a[i]+k)));
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
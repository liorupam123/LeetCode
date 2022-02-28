// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        map<double,int>m;
       int count=0;
       int ans=-1;
       for(int i=0;i<N;i++)
       {
           m.clear();
           count=0;
           pair<int,int>p=arr[i];
           for(int j=0;j<N;j++)
           {
               pair<int,int>q=arr[j];
               if(p==q)
               {
                   count++;
                   continue;
               }
               else
               {
                   double theta=(q.second-p.second)/((q.first-p.first)*1.0);
                   m[theta]++;
               }
           }
           for(auto it=m.begin();it!=m.end();it++)
           {
               ans=max(ans,it->second+count);
           }
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends
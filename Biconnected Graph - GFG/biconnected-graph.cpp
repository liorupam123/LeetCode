// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        // code here
        if(n==1) return 1;
        if(n==2 && e==1) return 1;
        unordered_map<int,vector<int>> p;
        for(int i=0;i<(2*e);i+=2){
            p[arr[i]].push_back(arr[i+1]);
            p[arr[i+1]].push_back(arr[i]);
        }
        for(auto m:p){
            if(m.second.size()<2){
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends
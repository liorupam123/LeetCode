// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
         int i,cnt=0;
       vector<int>v;
       if(!N)return -1;
       while(N){
           if(N%2)cnt++;
           v.push_back(N%2);
           N/=2;
       }
       if(cnt>1)return -1;
       else{
           for(i=0; i<v.size(); i++)if(v[i]==1)break;
           return i+1;
       }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
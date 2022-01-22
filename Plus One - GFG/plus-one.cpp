// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
            vector<int>v;
            // at first carry = 1, because we have to add 1 at the end
            int carry = 1;
            for(int i = N-1; i>=0; --i){
                int pu = (arr[i]+carry)%10;
                v.push_back(pu);
                // after that if the arr[i]!=9, we don't have to carry anything
                if(arr[i]!=9){
                    carry=0;
                }
            }
            // if the first element of the array == 9, it means 9+1 =10, so we have to add 1
            // at the end of the array
            if(carry==1 && arr[0]==9){
                v.push_back(1);
            }
            // reverse the answer array
            reverse(v.begin(), v.end());
            return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
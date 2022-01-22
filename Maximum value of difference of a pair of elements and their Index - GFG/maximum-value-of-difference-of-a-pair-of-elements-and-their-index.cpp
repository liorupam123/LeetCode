// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

// just take min_plus_inex1 and max_plus_index1 --> difference
//  min_plus_inex2 and max_plus_index2 --> difference
// return the maximum of two difference
class Solution {
  public:
    int maxValue(int arr[], int N) {
        // code here
         int min1=INT_MAX, min2=INT_MAX;
         int max1=INT_MIN, max2=INT_MIN;
      for(int i=0;i<N;i++){
          min1=min(min1,i+arr[i]);
          max1=max(max1,i+arr[i]);
          
          min2=min(min2,i-arr[i]);
          max2=max(max2,i-arr[i]);
      }
      return max(max1-min1,max2-min2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
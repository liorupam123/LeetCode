// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
         int i = 0, j = 0;
       int len = INT_MAX;
       int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
       while(j < S.length()){
           if(cnt_0 && cnt_1 && cnt_2){
               len = min(len,j-i);
               if(S[i] == '0') cnt_0--;
               if(S[i] == '1') cnt_1--;
               if(S[i] == '2') cnt_2--;
               i++;
           }
           else{
               if(S[j] == '0') cnt_0++;
               if(S[j] == '1') cnt_1++;
               if(S[j] == '2') cnt_2++;
               j++;
           }
       }
       
       while(i < S.length()){
           if(cnt_0 && cnt_1 && cnt_2) len = min(len,j-i);
           if(S[i] == '0') cnt_0--;
           if(S[i] == '1') cnt_1--;
           if(S[i] == '2') cnt_2--;
           i++;
       }
       
       return len == INT_MAX ? -1 : len;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
         int n = a.length();
        int m = b.length();
        int i = 0;
        int j = 0;
        
        // mark start (since where the a string in b is start)
        int start = -1;
        // keep checking from where the start of a is in b
        while(i<n){
            if(b[j]!=a[i]){
                // if not a[i] == b[j], keep moving a;
                i++;
                start = -1;
            }
            else{
                // if you got a[i] == b[j], There are two possibilites;
                // 1: you got the actual start point of a in b;
                // 2: it is just common character in both a and b;
                if(start==-1){
                    start = i;
                }
                i++;
                j++;
            }
        }
        // if start is unmarked, b can not be made from a;
        if(start==-1){
            return -1;
        }
        // ans is actual count of required number of a string
        int ans = 0;
        if(i!=0){
            // if i!=0,  we have already used part of a string, so increase count
            ans = 1;
        }
        while(j<m){
            if(i == n){
                // if we reach end of A, then again start
                i = 0;
            }
            if(i == 0){
                // if i == 0 means we are required one more A string
                ans++;
            }
            if(b[j]!=a[i]){
                // if charracters dont match 
                return -1;
            }
            else if(b[j] == a[i]){
                // if characters match, increase i and j;
                j++;
                i++;
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends
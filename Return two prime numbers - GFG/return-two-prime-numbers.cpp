// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool is_prime(int n)
    {
        if(n == 2 || n == 3)
        return true;
        
        if(n % 2 == 0 || n % 3 == 0)
        return false;
        
        for(int i = 5; i * i <= n; i += 6)
        {
            if(n % i == 0 || n % (i + 2) == 0)
            return false;
        }
        
        return true;
    }

    vector<int> primeDivision(int n){
        
        for(int i = 2; i <= n; i++)
        {
            if(is_prime(i) && is_prime(n - i))
            {
                return {i, n - i};
            }
        }
        
        return {};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends
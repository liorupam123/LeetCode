// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
// max operation, delete str1 and insert all the elements of str2
// operation number --> str1.size() + str2.size()

// now come to the question, minimum
// deletion = str1.size() - lcs
// insertion = str2.size() - lcs

// total --> str1.size() + str2.size() - 2 * lcs

	public:

	int minOperations(string s1, string s2){
	    
	    int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      
        if(n==0 || m==0) return 0;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
            }
        }
        int ans = n + m - 2*dp[n][m];
        return ans;
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
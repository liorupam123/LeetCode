class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        int m = s2.size();
       
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      
        if(n==0 || m==0) return 0;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(0 + dp[i][j - 1], 0 + dp[i - 1][j]);
            }
        }
        
        return dp[n][m];
    }
};
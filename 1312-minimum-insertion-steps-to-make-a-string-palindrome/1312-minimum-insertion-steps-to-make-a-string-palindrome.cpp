// maximum operation to make a string palindrom is s.size();
// s + reverse(s) --> is a palindrom 

// now come to this question, keep the longest palindrom subsequence portion a side
// ans = s.size() - longest palindrom subsequence
class Solution {
public:
    
    int minInsertions(string s1) {
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
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return n - dp[n][m];
    }
};
class Solution {
public:    
    int solve(vector<vector<int>> &grid,int n, vector<vector<int>> &dp, int i, int j){
        if(i == grid.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = 0; k < n; k++){
            if(k == j) continue;
            int curr = solve(grid,n, dp, i + 1, k);
            mini = min(mini, curr);
        }
        if(mini != INT_MAX) mini += grid[i][j];
        return dp[i][j] = mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid[0].size() == 1) return grid[0][0];
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++)
            ans = min(ans, solve(grid,n, dp, 0, i));
        return ans;
    }
};
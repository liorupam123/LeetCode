class Solution {
public:
    int path(vector<vector<int>>& grid, int m, int n, int row_start, int col_start,unordered_map<string,int>&mp){
      
        // we have to find the minimum cost here
        // so, when we are reaching out of the bound, return INT_MAX (maximum value)
        if (row_start >= m ||  col_start >= n) {
            return 100000;
        }
      
        // when we have reached the last cell return the value of the last cell
        if (row_start == m - 1 && col_start == n - 1) {
            return grid[row_start][col_start];
        }
      
        string currentKey = to_string(row_start) + "_" + to_string( col_start);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
      
        // moving right or down, add the value of the index everytime 
        int down = grid[row_start][col_start] + path(grid, m, n, row_start + 1, col_start,mp);
        int right = grid[row_start][col_start] + path(grid, m, n, row_start, col_start + 1,mp);
        int minVal = min(down, right);
        mp[currentKey] = minVal;
        return mp[currentKey];
    }
    
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<string,int> mp;
        int lowestSum = path(grid, m, n, 0, 0,mp);
        return lowestSum;
    }
};
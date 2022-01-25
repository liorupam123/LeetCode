class Solution {
public: 
    int path(vector<vector<int>>& obstacleGrid, int m, int n, int row_start, int col_start,unordered_map<string,int>&mp){
        
        // checking boudary cases --> we are not moving out of the bound
        if (row_start >= m || col_start >= n || obstacleGrid[row_start][col_start]==1) {
            return 0;
        }    
      
        // when we have reached m-1 and n-1, we reached the destination return 1
        if (row_start == m-1 && col_start == n-1) {
            return 1;
        }
        // obstacleGrid[row_start][col_start] == 1 means it is obstacle, we can't move by that
        // if(obstacleGrid[row_start][col_start]==1){
        //   return 0;
        // }
        // key of --> i and j
        string currentKey = to_string(row_start) + "_" + to_string( col_start);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }

        // we can move in two direction
        // right --> row,col+1
        // down -->  row+1,col
        int right =  path(obstacleGrid,m, n, row_start, col_start+1,mp);
        int down =  path(obstacleGrid,m, n, row_start+1, col_start,mp);
      
        // at the end return total ways
        int ans = right + down;
        mp[currentKey] = ans;
        return mp[currentKey];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        unordered_map<string,int> mp;
        return  path(obstacleGrid,m,n,0,0,mp);
    }
};
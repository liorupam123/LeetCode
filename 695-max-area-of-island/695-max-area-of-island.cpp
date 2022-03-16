class Solution {
public:
  
     void numIslandsRec(int i, int j, int n , int m, vector<vector<int>>& grid, int &cnt){
        
            if(i < 0 || i>=n ||j < 0 || j >=m || grid[i][j] == 0){
            return;
            }
            cnt++;
            // don't forget to make the land a water
            grid[i][j] = 0;
        
            numIslandsRec(i+1, j, n, m, grid,cnt);
        
            numIslandsRec(i-1, j, n, m, grid,cnt);
        
            numIslandsRec(i, j+1, n, m, grid,cnt);
        
            numIslandsRec(i, j-1, n, m, grid,cnt);
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
              int cnt = 0;
                if(grid[i][j] == 1){
                    numIslandsRec(i, j, n, m, grid,cnt);
                }
                 ans = max(ans,cnt);
            }
         
        }
        
        return ans;
    }
};
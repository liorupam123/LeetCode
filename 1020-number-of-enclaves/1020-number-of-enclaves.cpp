class Solution {
public:
    void numIslandsRec(int i, int j, int n , int m, vector<vector<int>>& grid){
        
				 if(i < 0 || i>=n ||j < 0 || j >=m || grid[i][j] == 0){
            return;
         } 
				
        // don't forget to make the land a water
        grid[i][j] = 0 ;
        
            numIslandsRec(i+1, j, n, m, grid);
        
            numIslandsRec(i-1, j, n, m, grid);
        
            numIslandsRec(i, j+1, n, m, grid);
        
            numIslandsRec(i, j-1, n, m, grid);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        int island = 0;
      
        for(int i=0; i<n; i++)                    // first and last column
            numIslandsRec(i,0,n,m,grid), numIslandsRec(i,m-1,n,m,grid);
        
        for(int j=0; j<m; j++)
            numIslandsRec(0,j,n,m,grid), numIslandsRec(n-1,j,n,m,grid);  // first and last row
      
      
        // after removing the border connected cases 
        // the no of times we ran dfs will give us no of  discounted lands
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 ){
                    island++;   
                }
            }
        }
        
        return island;
    }
};
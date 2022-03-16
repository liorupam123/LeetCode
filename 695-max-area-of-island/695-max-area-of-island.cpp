class Solution {
public:
  
     void numIslandsRec(vector<vector<int>>& grid,int currentRow,int currentCol,int m,int n,int &cnt){
        queue<pair<int,int>>q;
        q.push({currentRow,currentCol});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curr_row = it.first;
            int curr_col = it.second;
            if(curr_row < 0 || curr_row>=m ||curr_col < 0 || curr_col >=n || grid[curr_row][curr_col] == 0){
            continue;
            }
            cnt++;
            grid[curr_row][curr_col] = 0;
            q.push({curr_row-1,curr_col});
            q.push({curr_row,curr_col+1});
            q.push({curr_row+1,curr_col});
            q.push({curr_row,curr_col-1});
        }
        return;
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
                    numIslandsRec(grid,i, j, n, m,cnt);
                }
                 ans = max(ans,cnt);
            }
         
        }
        
        return ans;
    }
};
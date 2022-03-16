class Solution {
public:
    
    void numIslandsRec(vector<vector<char>>& grid,int currentRow,int currentCol,int m,int n){
        queue<pair<int,int>>q;
        q.push({currentRow,currentCol});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curr_row = it.first;
            int curr_col = it.second;
            if(curr_row < 0 || curr_row>=m ||curr_col < 0 || curr_col >=n || grid[curr_row][curr_col] == '0'){
            continue;
            }
            grid[curr_row][curr_col] = '0';
            q.push({curr_row-1,curr_col});
            q.push({curr_row,curr_col+1});
            q.push({curr_row+1,curr_col});
            q.push({curr_row,curr_col-1});
        }
        return;
    }
     
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    island++;
                    numIslandsRec(grid,i, j, n, m);
                }
            }
        }
        
        return island;
    }
};
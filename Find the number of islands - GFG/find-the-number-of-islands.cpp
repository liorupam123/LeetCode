// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
      void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid, int n, int m) {
       if(row < 0 || col < 0 || row == n || col == m || vis[row][col] || grid[row][col] == '0')
           return;
           
       vis[row][col] = true;
       
       dfs(row + 1, col, vis, grid, n, m);
       dfs(row - 1, col, vis, grid, n, m);
       dfs(row, col + 1, vis, grid, n, m);
       dfs(row, col - 1, vis, grid, n, m);
       dfs(row + 1, col + 1, vis, grid, n, m);
       dfs(row + 1, col - 1, vis, grid, n, m);
       dfs(row - 1, col - 1, vis, grid, n, m);
       dfs(row - 1, col + 1, vis, grid, n, m);
   }    

 

int numIslands(vector<vector<char>>& grid) {
       
       int n = grid.size();
       int m = grid[0].size();
       
       vector<vector<bool>> vis(n, vector<bool> (m, false));
       
       int ans = 0;
       for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
               if(grid[i][j] == '1' && vis[i][j] == false) {
                   dfs(i ,j ,vis, grid, n, m);
                   ans++;
               }
           }
       }
       
       return ans;
   }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
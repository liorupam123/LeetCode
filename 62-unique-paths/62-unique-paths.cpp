class Solution {
public:
    int path(int m, int n, int row_start, int col_start,unordered_map<string,int>&mp){
      
        // checking boudary cases --> we are not moving out of the bound
        if (row_start >= m || col_start >= n) {
            return 0;
        }    
      
        // when we have reached m-1 and n-1, we reached the destination return 1
        if (row_start == m-1 && col_start == n-1) {
            return 1;
        }
        // key of --> i and j
        string currentKey = to_string(row_start) + "_" + to_string( col_start);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }

        // we can move in two direction
        // right --> row,col+1
        // down -->  row+1,col
        int right =  path(m, n, row_start, col_start+1,mp);
        int down =  path(m, n, row_start+1, col_start,mp);
      
        // at the end return total ways
        int ans = right + down;
        mp[currentKey] = ans;
        return mp[currentKey];
    }
    
    int uniquePaths(int m, int n){
        unordered_map<string,int> mp;
        int totalPaths = path(m, n, 0, 0,mp);
        return totalPaths;
    }
};
class Solution {
public:
    int mod = 1e9+7;
    int totalways(int m, int n, int maxMove, int startRow, int startColumn,unordered_map<string,int>&mp) {
      
        // when we are getting out of the boundary, we are getting one of answers,so return 1
        if(startRow > m-1 || startRow < 0 || startColumn > n-1 || startColumn < 0){
          return 1;
        }
        // when the number of moves became 0, we can't do anyhting , return 0
        if(maxMove<=0) return 0;
      
        string currentKey = to_string(startRow) + "_" + to_string(startColumn) + "_" + to_string(maxMove);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
      
        // we can move 4 side right,left,up,down
        // right = row,col+1 , left = row,col-1 , up = row-1,col , down = row+1,col
        // everytime decrease the number of total moves
        long long int right = totalways(m,n,maxMove-1,startRow,startColumn+1,mp)%mod;
        long long int left = totalways(m,n,maxMove-1,startRow,startColumn-1,mp)%mod;
        long long int up = totalways(m,n,maxMove-1,startRow-1,startColumn,mp)%mod;
        long long int down = totalways(m,n,maxMove-1,startRow+1,startColumn,mp)%mod;
      
        // we have to return total ways, so add all possible 4 paths
        return mp[currentKey] = (right+left+up+down)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        unordered_map<string,int> mp;
        return totalways(m,n,maxMove,startRow,startColumn,mp)%mod;
    }
};
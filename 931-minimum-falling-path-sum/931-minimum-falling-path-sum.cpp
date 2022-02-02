// 3^n --> n rows 
// O(n)
class Solution {
public:
     int pathsum(vector<vector<int>>& matrix,int n,int i, int j,unordered_map<string,int>&mp){
       
        // if j reaches ount of the bound return max
        if(j<0 || j>=n)  return 100001;
        
        // we don't have any particular ending point to reach
        // whenever starting point reached any end point (n-1), return the cost of that index
        if(i==n-1){
          return matrix[i][j];
        }
        
        string currentKey = to_string(i) + "_" + to_string(j);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
       
        // we have to return the cost, so add matrix[i][j]
        // (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
        int a=matrix[i][j]+pathsum(matrix,n,i+1,j,mp);
        int b=matrix[i][j]+pathsum(matrix,n,i+1,j-1,mp);
        int c=matrix[i][j]+pathsum(matrix,n,i+1,j+1,mp);
        return mp[currentKey] = min(a,min(b,c));
        
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int miner=INT_MAX;
        unordered_map<string,int> mp;
        // starting position is not fixed so we are running a loop and starting from every index
        // and checking which index is giving minimum
        for(int i=0;i<n;i++){
            miner=min(miner,pathsum(matrix,n,0,i,mp));
        }
        return miner;
    }
};
class Solution {
public:
    int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle,int n,unordered_map<string,int>&mp) {
  
    // we don't have any particular ending point to reach
    // whenever starting point reached any end point (n-1), return the cost of that index
    if(i==n-1) return triangle[i][j];
      
    string currentKey = to_string(i) + "_" + to_string(j);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }

    // we have to return the cost, so add triangle[i][j]
    // down ==> i+1,j right down ==> i+1,j+1
    int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,mp);
    int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,mp);

    return mp[currentKey] = min(down, diagonal);
  
}

    int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
        unordered_map<string,int> mp;
        return minimumPathSumUtil(0,0,triangle,n,mp);
    }
};
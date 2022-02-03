/* 
       0 0 0 0 0 0    we are taking minimum because of avoiding rectangle
       0 1 0 1 0 0
       0 1 0 1 1 1     <----------- DP MATRIX
       0 1 1 1 2 2     +1 , to get 2, 1 1
       0 1 0 0 1 0                    1 2  --> return 2*2 = 4
*/
class Solution {
public:
    int largestSquare(vector<vector<char>>& matrix,int n,int m,int i,int j,unordered_map<string,int>&mp){
      
      // if we are getting out of the bound and matrix[i][j]=='0', return 0
      if(i>=n || j>=m || matrix[i][j]=='0') return 0;
      
      string currentKey = to_string(i) + "_" + to_string(j);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
      
      // right = i,j+1 , down=i+1,j , corner = i+1,j+1
      
      int right = largestSquare(matrix,n,m,i,j+1,mp);
      int down = largestSquare(matrix,n,m,i+1,j,mp);
      int corner = largestSquare(matrix,n,m,i+1,j+1,mp);
      int ans = 1 + min({right,down,corner});
      return mp[currentKey] = ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
      
        int ans = 0;
        unordered_map<string,int> mp;
        // iterate through the matrix and when a char is 1, then only call the function
        // because it is written that square containing only 1's 
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(matrix[i][j]=='1'){
              // return the area of the largest length of the square
              int temp = largestSquare(matrix,n,m,i,j,mp);
              ans=max(ans,temp);
            }
          }
        }
        // return the area
        return ans*ans;
    }
};
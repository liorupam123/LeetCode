// Time complexity   = O(N*M)
// Space Complexity: O(M + N), for storing hash tables.
class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        int row[m];
        int col[n];
        
        // take a row vector and mark all index as false
        for(int i=0;i<m;i++)
            row[i]=false;
        
        // take a col vector and mark all index as false
        for(int i=0;i<n;i++)
            col[i]=false;
        
        // iterate through the matrix
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // if matrix[i][j]==0
                if(v[i][j]==0){
                    // set the index of the row and col vector as true
                    row[i]=true;
                    col[j]=true;
                }
            }
         }
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // whenever row or col of that index == true, set the matrix[i][j]=0
                if( row[i]==true  ||  col[j]==true){
                    v[i][j]=0;
                }
            }
         }
    
    }
};
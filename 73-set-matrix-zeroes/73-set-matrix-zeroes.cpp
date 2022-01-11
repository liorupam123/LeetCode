// T.C =O(M*N*(M+N))    S.C=O(M*N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        // take a temp matrix of size m*n, of all 1
        int temp[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                temp[i][j]=1;
        
        // now iterate through the matrix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // when matrix[i][j] == 0
                if(v[i][j]==0){
                  
                // set the row and col of the temp matrix = 0
                for(int k=0;k<m;k++)
                    temp[k][j]=0;
                    
                    for(int k=0;k<n;k++)
                        temp[i][k]=0;
                }
            } 
        }
        // now iterate and remake the value of matrix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              // if temp[i][j]==0 , set the matrix[i][j=0]
               if(temp[i][j]==0)
                   v[i][j]=temp[i][j];
                else
                    //else, keep the matrix[i][j as it is]
                    v[i][j]=v[i][j];
            }
        }
        
    }
};
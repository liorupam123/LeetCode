// start with the top right corner
// O(n+m), not o(m*n)--> we are not checking all elements
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix[0].size()-1;
        // boundary check
        while(r<matrix.size()&&c>=0){
          if(matrix[r][c]==target)  return true;
          // when target is smaller , delete the col, co--
          else if(matrix[r][c]>target)  c--;
          // when target is greater , delete the row, ro++
          else if(matrix[r][c]<target)  r++;
        }
       return false;
    }
};
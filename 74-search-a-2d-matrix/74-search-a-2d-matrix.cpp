//1. to find potential row
//2. find target in potential row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int potential_row = binarysearchselectrow(matrix,target);
      
      if(potential_row==-1) return false;
      
      bool isfound = binarysearch(matrix,target,potential_row);
      return isfound;
    }
    bool binarysearch(vector<vector<int>>& matrix, int target,int r){
      int lo = 0;
      int hi = matrix[0].size()-1;
      while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(matrix[r][mid]==target)  return true;
        else if(matrix[r][mid]>target) hi=mid-1;
        else if(matrix[r][mid]<target) lo=mid+1;
      }
      return false;
    }
    int binarysearchselectrow(vector<vector<int>>& matrix, int target){
      int lo = 0;
      int hi = matrix.size()-1;
      int lc = matrix[0].size()-1;
      while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        
        if(matrix[mid][0]<=target && target<=matrix[mid][lc]){
          return mid;
        }
        else if(matrix[mid][0]<target){
          lo = mid + 1;
        }
        else if(matrix[mid][0]>target){
          hi = mid - 1;
        } 
      }
      return -1;
    }
};
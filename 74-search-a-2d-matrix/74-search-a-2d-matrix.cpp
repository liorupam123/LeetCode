// O(logm + logn) ==> O(log(m*n))
//1. to find potential--> row O(logm)
//2. find target in potential--> row O(logn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
      // at first search the potential row
      int potential_row = binarysearchselectrow(matrix,target);
      
      // if potential row == -1, thats means the the target is not present , return false
      if(potential_row==-1) return false;
      
      // else , search the element in the row
      bool isfound = binarysearch(matrix,target,potential_row);
      return isfound;
    }
   
    // search the element in the row function
    bool binarysearch(vector<vector<int>>& matrix, int target,int r){
      // simple binary search
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
  
    // search the potential row function
    int binarysearchselectrow(vector<vector<int>>& matrix, int target){
      int lo = 0;
      int hi = matrix.size()-1;
      int lc = matrix[0].size()-1;
      while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        
        // checking if the target can present between the first and last element of the row
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
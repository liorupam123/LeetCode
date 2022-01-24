class Solution {
public:
    int search(vector<int>& nums, int target) {
      int left=0,right=nums.size()-1;
      while(left<=right){
        // (left + right )/2 will show integer overflow for big inputs
        int m =left+(right-left)/2; 
        // if middle element == target , return mid index
        if(nums[m]==target){ 
          return m;
        }
        // if mid element is greater , target stands at the left, so right = mid -1
        else if(nums[m]>target){ 
          right=m-1;
        }
        // if mid element is lower , target stands at the right, so left = mid +1
        else{ 
          left=m+1;
        }
      }
      // element is not present...
      return -1; 
    }
  
};
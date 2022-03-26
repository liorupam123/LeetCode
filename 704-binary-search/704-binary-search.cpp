class Solution {
public:
    int recursiveBS(vector<int>& nums,int left,int right, int target){
      
      while(left<=right){
        int mid =left+(right-left)/2;
      
        if(nums[mid]==target){ 
            return mid;
        }
        else if(nums[mid]>target){ 
            return recursiveBS(nums,left,mid-1,target);
        }
        else{ 
            return recursiveBS(nums,mid+1,right,target);
        }
      }
      return -1;  
    }
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      return recursiveBS(nums,0,n-1,target);
      
    }
  
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // linear search
        int n = nums.size();
        int pos = -1;
        for(int i=0;i<n;i++){
          if(nums[i]==target) return i;
          else if(nums[i]<target) pos = i;
        }
        return pos+1;
    }
};
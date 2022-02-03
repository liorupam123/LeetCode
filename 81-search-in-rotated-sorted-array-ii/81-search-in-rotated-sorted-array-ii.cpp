class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            //avoid duplicates
            while(low<high && nums[low]==nums[low+1])low++;
            while(high>low && nums[high]==nums[high-1])high--;
          
            int mid=(low+high)/2;
          
            if(nums[mid]==target)
                return true;
            
            if(nums[mid]>=nums[low])//left side is sorted
            {
                if(target<nums[mid] && target>=nums[low])//if left side contains the target (range check)
                    high=mid-1;
                else//if doesn't contains target, goto right half of the array
                    low=mid+1;
            }
            else//right side is sorted
            {
                if(target<=nums[high] && target>nums[mid])//if right side contains target
                    low=mid+1;
                else//else goto left part 
                    high=mid-1;
            }
        }
        return false;
    }
};
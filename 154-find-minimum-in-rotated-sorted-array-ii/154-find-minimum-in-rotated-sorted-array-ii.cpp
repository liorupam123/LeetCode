// 1 2 3 3 3 3 3 3 3 4
// after rotation:- 3(start) 3 3 3 3(mid) 3 4 1 2 3(end)

// here we just have to check the == case, if nums[mid]==nums[end] --> end--
// except that everything is same as I

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low<=high){
            mid =  low + (high-low)/2;
            if(nums[mid]<nums[high]){
                high = mid;
            }
            else if(nums[mid]>nums[high]){
              low = mid +1;
            }
            else{
                high--;
            }
        }
        return nums[mid];
    }
};
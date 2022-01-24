// 1 2 3 4 5 6 7 8 9
// after rotation --> 4(low) 5 6 7 8(mid) 9 1 2 3(high)

// if nums[mid] > nums[high] , it means right wala part is not sorted, its rotated 
// if nums[mid] > nums[high] , it clearly means that minimum number is lying in [mid,high]
// low = mid + 1

// 9(low) 1(mid) 2 3(high)
// if nums[mid] < nums[high] , it means it is sorted
// minimum number is lying in [low,mid]
// high = mid

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
            else{
                low = mid+1;
            }
        }
        return nums[mid];
    }
};
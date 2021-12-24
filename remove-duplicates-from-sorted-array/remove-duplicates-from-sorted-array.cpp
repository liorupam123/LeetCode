class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        // take a pointer at first index
        int left = 0;
        for(int right =1; right< nums.size(); right++){
           // if nums[left]!=nums[right] ==> index++;
           if(nums[left] != nums[right])
               left++;
               // update the left element
               nums[left] = nums[right];
           }
    // return left+1 ==> next index, array starts from 0
    return left+1;
    }
};
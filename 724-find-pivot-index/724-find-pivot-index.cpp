class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, left_sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        for(int i=0;i<n;i++){
            sum -= nums[i];
            if(sum == left_sum) return i;
            left_sum += nums[i];
        }
        return -1;
        
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int curr_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
          
            curr_sum += nums[i];
            max_sum = max(curr_sum, max_sum);
            // if current sum is < 0, make current sum = 0, that's the algorithm
            if(curr_sum < 0) curr_sum = 0;
        }
        return max_sum;
    }
};
// Instead of only calculating the maximum subarray, we also calculate the minimum subarray.
/* The reason is, that to find a maximum subarray in a circular array where it splits into to parts, we can find the minimum subarray and subtract it from the total sum and it will give us the same solution. */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = nums[0], min_sum = nums[0], total_sum = nums[0], prev_min = nums[0], prev_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
          
            // at first we are calculating the total sum
            total_sum += nums[i];
            
            // now we are calculating the previous_sum
            // then previous_maxsum
            prev_max = max(prev_max + nums[i], nums[i]);
            max_sum = max(max_sum, prev_max);
            
            // now we are calculating the previous_sum
            // then previous_minsum
            prev_min = min(prev_min + nums[i], nums[i]);
            min_sum = min(min_sum, prev_min);
        }
        
        // if sum == min_sum, return previous_maxsum
        // if sum != min_sum,  return total sum - previous_minsum
        return total_sum == min_sum ? max_sum : max(max_sum, total_sum-min_sum);
    }
};
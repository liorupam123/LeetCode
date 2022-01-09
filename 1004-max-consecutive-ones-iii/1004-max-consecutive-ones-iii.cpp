class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0, zeros = 0, res = 0;
        
        while(end<nums.size()){
            
            // If we reached a zero, increase the zero counter.
            if (nums[end]==0)
                zeros++;
            
            // If the number of zeros is more than k, we finished with this subarray.
            // Now we can save the length and increament start to find new size
            if(zeros>k){
              while (zeros > k) {
                if (nums[start]==0) zeros--;
                start++;
              } 
            }
            
            res = max(res, end - start + 1);
            end++;
        }
        
        return res;
    }
};
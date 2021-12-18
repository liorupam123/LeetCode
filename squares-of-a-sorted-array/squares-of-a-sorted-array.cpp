class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        vector<int> ans(n);
        for(int k=n-1;k>=0;k--){
          if(abs(nums[start])<abs(nums[end])){
            ans[k]=nums[end]*nums[end];
            end--;
          }
          else if(abs(nums[start])>=abs(nums[end])){
            ans[k]=nums[start]*nums[start];
            start++;
          }
        }
        
        return ans;
    }
};
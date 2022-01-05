class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), mx=0;
        for(int i=0;i<n;i++){
          if(nums[i]==1){
              int j=i;
              while(j<n && nums[j]==1){
                j++;
              }
              mx = max(mx,j-i);
            } 
        }
        return mx;
    }
};
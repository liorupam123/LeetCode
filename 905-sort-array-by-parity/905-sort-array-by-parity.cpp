class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j=0;j<n;j++){
          if(nums[j]%2==0){
            swap(nums[i],nums[j]);
            i++;
          }
        }
        return nums;
    }
};
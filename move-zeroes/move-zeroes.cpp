class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int i=0,j=0;
        while(i<n && j<n){
          if(nums[i]==0){
            i++;
          }
          else{
            ans[j]=nums[i];
            i++;
            j++;
          }
        }
        for(int i=0;i<nums.size();i++){
          nums[i]=ans[i];
        }
    }
};
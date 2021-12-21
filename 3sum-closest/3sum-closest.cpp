class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, ans = 0 , diff = INT_MAX;
        for(int i=0;i<n-2;i++){
          for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                  return target;
                }
                else if(abs(target - sum) <= diff){
                  diff = abs(target - sum);
                  ans = sum;
                }
            }
          }
        }
        return ans;
    }
};
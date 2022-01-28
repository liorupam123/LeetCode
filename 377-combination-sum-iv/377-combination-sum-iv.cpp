class Solution {
public:
    int totalWays(vector<int>& nums,int target,unordered_map<int,int>&mp){
      if(target==0)  return 1;
      
      int currentkey = target;
      if(mp.find(currentkey)!=mp.end()){
         return mp[currentkey];
      }
      
      int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]<=target) {
                result += totalWays(nums, target - nums[i],mp);
            }
        }
       mp[currentkey] = result;
       return mp[currentkey];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        return totalWays(nums,target,mp);
    }
};
class Solution {
public:
      int targetSum(vector<int>& nums,int currentIndx, int target,unordered_map<string,int>&mp){
            if(target == 0 &&  currentIndx==nums.size() )
            return 1;
        
            if( target!=0 && currentIndx >= nums.size())
            return 0;
            
            string currentkey = to_string(currentIndx) + "_" + to_string(target);
            if(mp.find(currentkey)!=mp.end()){
              return mp[currentkey];
            }
            int pick = targetSum(nums,currentIndx+ 1, target - nums[currentIndx],mp);
            int nonpick=targetSum(nums,currentIndx + 1, target + nums[currentIndx],mp);
         
            mp[currentkey] = pick+nonpick;
            return mp[currentkey];
     }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> mp;
        return targetSum(nums,0,target,mp);
    }
};
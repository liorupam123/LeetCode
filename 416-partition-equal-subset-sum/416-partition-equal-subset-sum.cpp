class Solution {
public:
    bool subsetsum(vector<int>& nums,int n,int target,int currentIndex,unordered_map<string,int>&mp){
      if(target==0){
        return true;
      }
      if(currentIndex>=n){
        return false;
      }
      string currentKey = to_string(target) + "_" + to_string(currentIndex);
        
        if(mp.find(currentKey)!=mp.end()){
           return mp[currentKey];
        }

      bool pick = false;
      if(nums[currentIndex]<=target){
         pick = subsetsum(nums,n,target-nums[currentIndex],currentIndex+1,mp);
      }
      if(pick){
        return true;
      }
      
      bool notpick = subsetsum(nums,n,target,currentIndex+1,mp);
      mp[currentKey] = ( pick || notpick);
        
        return  mp[currentKey];

      
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
        }
        if(sum%2!=0)  return false;
        int target = sum/2;
        unordered_map<string,int>mp;
        bool ans = subsetsum(nums,n,target,0,mp);
        return ans;
        
    }
};
class Solution {
public:
    bool subsetsum(vector<int>& nums,int n,int target,vector<vector<int>>&mp){
      if(target==0){
        return true;
      }
      if(n<=0){
        return false;
      }
      if(mp[n][target]!=-1) return mp[n][target];

      
      if(nums[n-1]<=target){
         mp[n][target] = subsetsum(nums,n-1,target-nums[n-1],mp) || subsetsum(nums,n-1,target,mp);
         return  mp[n][target];
      }
      else{
        mp[n][target] = subsetsum(nums,n-1,target,mp);
        return  mp[n][target];
      }  
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
        }
        if(sum%2!=0)  return false;
        int target = sum/2;
        vector<vector<int>> mp(n+1,vector<int>(target+1,-1));
        bool ans = subsetsum(nums,n,target,mp);
        return ans;
        
    }
};
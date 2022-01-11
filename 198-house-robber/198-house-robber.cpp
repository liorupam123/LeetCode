class Solution {
public:
    int maxmoneylooted(vector<int> &nums,int current,unordered_map<int,int>&mp){
      
      if(current>=nums.size()){
        return 0;
      }
      
      int key = current;
      if(mp.find(key)!=mp.end()){
        return mp[key];
      }
      
      int lootenge = maxmoneylooted(nums,current+2,mp) + nums[current];
      int nehilootenge = maxmoneylooted(nums,current+1,mp);
      
      mp[key] = max(lootenge,nehilootenge);
      return mp[key];
    }
    int rob(vector<int>& nums) {
      
        unordered_map<int,int> mp;
        return maxmoneylooted(nums,0,mp);
    }
};
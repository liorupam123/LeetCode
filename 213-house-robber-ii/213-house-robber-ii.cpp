class Solution {
public:
       int maxMoneyLooted(vector<int>&nums,int n, int currentIndex,unordered_map<int,int>&mp){
        
        //base condition
        
        if(currentIndex >= n){
            return 0;
        }
        //choices
        int currentKey = currentIndex;
        
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        
        int lootenge = maxMoneyLooted(nums,n,currentIndex+2,mp) + nums[currentIndex];
        int nhiLootenge = maxMoneyLooted(nums,n,currentIndex+1,mp);
        
        mp[currentKey] = max(lootenge,nhiLootenge);
        
        return   mp[currentKey];
        
    }
  
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)return nums[0];
        unordered_map<int,int>mp,mp1;
      
        // make a circle from 0 to n-1 and check that 0 to n-2 and 1 to n-1
        // 0 and n-1 is beside each other
        int first = maxMoneyLooted(nums,n-1,0,mp);
        int second = maxMoneyLooted(nums,n,1,mp1);
        return max(first,second);
        
    }
};


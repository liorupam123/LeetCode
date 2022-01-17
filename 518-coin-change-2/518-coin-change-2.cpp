class Solution {
public:
    int numberofcoins(vector<int>& coins, int amount,int currentIndex,unordered_map<string,int>&mp){
      if(amount==0) return 1;
      if(currentIndex>=coins.size())  return 0;
      
      string currentKey = to_string(amount) + "_" + to_string(currentIndex);
        
        if(mp.find(currentKey)!=mp.end()){
           return mp[currentKey];
        }
      
      int pick = 0;
      if(coins[currentIndex]<=amount){
        pick = numberofcoins(coins,amount-coins[currentIndex],currentIndex,mp);
      }
      int notpick = numberofcoins(coins,amount,currentIndex+1,mp);
      mp[currentKey] = pick + notpick;
      return mp[currentKey];
    }
    int change(int amount, vector<int>& coins) {
        unordered_map<string,int>mp;
        int ans = numberofcoins(coins,amount,0,mp);
        return ans ;
    }
};
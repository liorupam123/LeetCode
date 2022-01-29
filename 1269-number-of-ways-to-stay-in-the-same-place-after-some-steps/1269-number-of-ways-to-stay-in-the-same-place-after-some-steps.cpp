class Solution {
public:
    long mod = 1e9+7;
    int totalWays(int steps,int arrLen,int currIndex,unordered_map<string,int>&mp){
      
      if(steps==0 && currIndex==0)  return 1;
      if(currIndex<0||currIndex>=arrLen||steps==0)			return 0;
      string currentKey = to_string(steps) + "_" + to_string(currIndex);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
      long long int right = totalWays(steps-1,arrLen,currIndex+1,mp)%mod;
      long long int left = totalWays(steps-1,arrLen,currIndex-1,mp)%mod;
      long long int stay = totalWays(steps-1,arrLen,currIndex,mp)%mod;
      long long int totalsteps = ((right+left+stay)%mod)%mod;
      mp[currentKey] = totalsteps;
      return mp[currentKey];
    }
    int numWays(int steps, int arrLen) {
        unordered_map<string,int> mp;
        int ans = totalWays(steps,arrLen,0,mp)%mod;
        return ans%mod;
    }
};
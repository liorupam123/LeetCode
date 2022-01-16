class Solution {
public:
    long long help(vector<vector<int>>& questions, int i,int n,unordered_map<long,long> &mp){
      if(i>=n){
        return 0;
      }
      int key = i;
      if(mp.find(key)!=mp.end()){
        return mp[key];
      }
      long long pick = questions[i][0]+help(questions,i+questions[i][1]+1,n,mp);
      long long notpick = help(questions,i+1,n,mp);
      long long ans = max(pick,notpick);
      mp[key] = ans;
      return mp[key];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        unordered_map<long,long> mp,mp1;
        long long final = help(questions,0,n,mp);
        
        return final;
        //return temp.size();
    }
};
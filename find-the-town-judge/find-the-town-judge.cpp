class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1,0); // making a count vector to store the trust count
      for(auto &t: trust){
        count[t[0]]--; // trust others , so --
        count[t[1]]++; // trusted by others , so ++
      }
      for(int i=1;i<=n;i++){
        if(count[i] == n-1) // who is trusted by n-1 peopel are the town judge
          return i;
      }
      return -1;
    }
};
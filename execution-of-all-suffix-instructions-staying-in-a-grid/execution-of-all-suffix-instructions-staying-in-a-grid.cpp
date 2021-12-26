class Solution {
public:
    bool isValid(int row , int col, int n){
      return (row>=0 && row<n && col>=0  && col< n);
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len = s.size();
        vector<int> ans;
        int row = startPos[0];
        int col = startPos[1];
        int currrow = row , currcol = col;
        for(int i=0;i<len;i++){
          currrow = row;
          currcol = col;
          int count = 0;
          for(int j=i;j<len;j++){
            if(s[j]=='U') currrow--;
            else if(s[j]=='D')  currrow++;
            else if(s[j]=='R')  currcol++;
            else  currcol--;
            if(isValid(currrow,currcol,n)){
              count++;
            }
            else{
              break;
            }
          }
          ans.push_back(count);
        }
        return ans;
    }
};
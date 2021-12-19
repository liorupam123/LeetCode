class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int s_len = s.size(), n = spaces.size();
        int i=0,j=0;
        string ans="";
        while(i<s_len && j<n){
          if(i==spaces[j]){
            ans +=" ";
            j++;
          }
          else{
            ans+=s[i];
            i++;
          }
        }
        // for including extra letters of the string
        while(i<s_len){
            ans+=s[i];
            i++;
          }
        return ans;
    }
};
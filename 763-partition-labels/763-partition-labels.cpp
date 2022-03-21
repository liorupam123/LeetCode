class Solution {
public:
    vector<int> partitionLabels(string S) {
      
        // unordered map of char and its last index
        unordered_map<char,int> map;
        vector<int> ans;
        if(S.size()==0)return ans;
        // updating the last index of charater
        for(int i=0;i<S.size();i++)
            map[S[i]]=i;
      
        // taking the maxindex = 0 and lastindex = -1
        int maxindex=0,lastindex=-1;
        for(int i=0;i<S.size();i++){
          
            // now iterate through the array and check the maxindex of the characters
            maxindex=max(maxindex,map[S[i]]);
            // when i reached the maxindex of one charater
            if(i==maxindex){
                // push the length in the answer
                ans.push_back(maxindex-lastindex);
                // update the lastindex with the maxindex
                lastindex=maxindex;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0;i<nums1.size();i++){
          st.insert(nums1[i]);
        }
        for(auto it : nums2){
          if(st.find(it)!=st.end()){
            ans.push_back(it);
            st.erase(it);
          }
        }
        return ans;
    }
};
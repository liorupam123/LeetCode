class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // storing the element and its count
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
          mp[nums[i]]++;
        }
        for(auto it:mp){
          
          // if any elements's count is > n/2
          if(it.second>n/3){
            // return the element
            ans.push_back(it.first);
          }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0;i<n-2;i++){
          int j = i+1;
          int k = n-1;
          
          while(j<k){
            
            if(nums[i]+nums[j]+nums[k] == 0){
              s.insert({nums[i],nums[j],nums[k]});
              j++;k--;
              
            }
            else if(nums[i]+nums[j]+nums[k] > 0){
              k--;
            }
            else{
              j++;
            }
            
          }
          
        }
        vector<vector<int>> final_ans(s.begin(),s.end());
        return final_ans;
    }
};
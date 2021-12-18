class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v, ans;
        int low = 0, high = nums.size() - 1, index1, index2;
        v = nums;
        sort(nums.begin(), nums.end());
        while(low < high){
          if(nums[low] + nums[high] > target) high--;
          else if(nums[low] + nums[high] < target) low++;
          else{
            index1 = nums[low], index2 = nums[high];
            break;
          }
        }
        for(int i = 0 ; i < v.size() ; i++){
          if(v[i] == index1 || v[i] == index2){
            ans.push_back(i);
          }
          if(ans.size() == 2) break;
        }
        return ans;
    }
};
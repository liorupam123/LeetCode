class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX, ans = 0;
        for(int i=0;i<n-2;i++){
          int j = i+1;
          int k = n-1;
          
          while(j<k){
            
            int sum = nums[i]+nums[j]+nums[k];
            if( sum == target){
              return target;
              // j++;k--;
              
            }
            else{
              if(sum > target){
                  k--;
              }
              else{
                  j++;
              }
              int temp_diff = abs(sum - target);
              if(diff>temp_diff){
                 diff = temp_diff;
                 ans = sum;
              } 
            } 
            
            
            
          }
          
        }
        return ans;
    }
};
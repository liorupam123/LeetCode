class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1 , count_zero = 0;
        for(int i=0;i<n;i++){
          if(nums[i]==0){
            count_zero++;
           //continue;
          }
          else  product *= nums[i];
        }
        if(count_zero == n){
          return nums;
        }
        if(count_zero==0){
          for(int i=0;i<n;i++){
             nums[i]=product/nums[i];
          }
        }
        else if(count_zero==1){
          for(int i=0;i<n;i++){
            if(nums[i]==0){
              nums[i]=product;
             }
            else{
              nums[i]=0;
            }
          }  
        }
        else if(count_zero>1){
          for(int i=0;i<n;i++){
              nums[i]=0;
            }
        }  
        return nums;
    }
};
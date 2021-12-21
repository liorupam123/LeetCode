class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =  nums.size() , count = 1;
        int majority_element = nums[0];
        for(int i=1;i<n;i++){
          if(count==0){
            count = 1;
            majority_element = nums[i];
          }
          else  if(nums[i]==majority_element){
            count++;
            
          }
          else if(nums[i]!=majority_element){
            count --;
          }
          
        }
        return majority_element;
      
    }
};
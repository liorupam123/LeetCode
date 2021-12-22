// two pointers
class Solution {
public:
     int findPairs(vector<int>& nums, int k) {
          sort(nums.begin(),nums.end());
         int n =  nums.size();
         int count = 0;
         int i = 0; int j = 1;
         while(i<n and j<n){
             if(nums[j] - nums[i] == k){
                 i++;
                 j++;
                 count++;
                 // to handle duplicates
                 while(j<n and nums[j]==nums[j-1]){
                     j++;
                 }
             }else if(nums[j]-nums[i] > k){
                 i++;
                 if(j-i==0){
                     j++;
                 }
             }else{
                 j++;
             }
             
         }
        return count;
          
     }
};
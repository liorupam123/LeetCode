class Solution 
{
public:
    // Function to calculate the number of subarrays having count of odd numbers lees than or equals to k
    int helper(vector<int>&nums,int k){
        int ans=0,i=0,count=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2!=0){
                count++;
            }
            while(i<=j && count>k){
                if(nums[i]%2!=0){
                    count--;
                }
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k){
        // Number of subarrays with count of odd numbers <=k = (Numbers of subarrays with count of odd numbers <k + Numbers of subarrays with count of odd numbers =k)
        // so if we exclude the number of subarrays with odd number count less than k from number of subarrays with odd number count equals to k , we'll get our answer.
        return helper(nums,k)-helper(nums,k-1);
    }
};
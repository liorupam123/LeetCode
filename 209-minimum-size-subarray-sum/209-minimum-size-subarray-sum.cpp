class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int res=INT_MAX;
        vector<int> out;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    int temp=j-i+1;
                    res=min(res,temp);
                    break;
                }
            }
        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
};
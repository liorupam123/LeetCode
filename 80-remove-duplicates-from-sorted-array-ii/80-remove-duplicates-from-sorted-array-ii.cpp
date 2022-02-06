class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]=2;
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(map[nums[i]]<=2&&map[nums[i]]>=1){
                nums[j++]=nums[i];
                map[nums[i]]--;
            }
        }
        return j;
    }
};
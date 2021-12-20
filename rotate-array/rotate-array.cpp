class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %=nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
//https://leetcode.com/problems/rotate-array/discuss/723103/C%2B%2B-oror-Easy-to-understand-oror-Multiple-Approaches
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    // Brute Force Solution Time O(N^2) & Auxiliary Space O(1)
    // Calculate the sum of elements to the left & right
    // of each index of nums vector and compare them to check equivalence
    int len=nums.size();
    if(len==1)
        return nums[0];
    for(int i=0;i<len;i++){
           // accumulate() takes O(N) time and for loop runs for n iterations.
           // So time taken by for loop is O(n*n)=O(N^2)
          int left=accumulate(nums.begin(),nums.begin()+i,0); 
          int right=accumulate(nums.begin()+i+1,nums.end(),0);
          if(left==right)
              return i;
    }
      return -1;
    }
};
class Solution {
public:
  void help(int i,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans)
  {
    if(i==nums.size()){
      ans.push_back(temp); // if index reached the last index there is no way to move furthur, so push the temp vector into the main answer
    }else{
    temp.push_back(nums[i]); // picking the element
    help(i+1,nums,temp,ans); // then moving into the next index
    temp.pop_back(); // Backtracking --> to remove the index
    help(i+1,nums,temp,ans); // not picking the index and moving into the next index
      
    }
    
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
      // take a temp/output vector to store every subsets into the main vector<vector<int>> ans
      // it's always necessery to take a vector into to push the vector into the main v<v<int> ans
      vector<int> temp;
      help(0,nums,temp,ans); // start with 0 index..
      return ans;
    }
};
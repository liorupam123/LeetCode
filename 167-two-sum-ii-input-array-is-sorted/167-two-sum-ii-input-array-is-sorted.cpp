class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //vector<int> ans;
        int n = numbers.size();
        int i = 0, j = n-1;
        while(i<=j){
          
          if(numbers[i]+numbers[j]==target){
              // ans.push_back(i+1);
              // ans.push_back(j+1);
              return {i+1,j+1};
          } 
          else if(numbers[i]+numbers[j]>target) j--;
          else  i++;

        }
        return {};
    }
};
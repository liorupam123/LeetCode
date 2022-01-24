class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int i = 0, j = nums.size()-1;
        int start = -1, end = -1;
        while(i <= j){
          
            int mid = i + (j-i)/2;
          
            // when mid element == target , target can present before / left as well --> first index, and after/right as well --> last index
            if(nums[mid] == target){ 
              
                // first index working with mid index, last index working with temp, temp is a variable to store first mid index...
               int temp = mid;
                
                //iterating left side of mid until target value is found
                while(mid > 0 && nums[mid-1] == target) 
                    mid--;   // 2 2  2 2(mid) 2
                start = mid; // first index..
              
                //iterating right side of mid until target value is found (here temp is equal to mid)
                while(temp < nums.size()-1 && nums[temp+1] == target) 
                    temp++;     // 2 2 2(mid) 2 2 2
                end = temp;     // last index..
                
                ans.push_back(start);
                ans.push_back(end);
                // returning answer from here... like mid in bs
                return ans; 
            }
          
            // if target is less than or greater than, everything is normal like BS
            else if(nums[mid] > target)
                j = mid-1;
            else
                i = mid+1;
        }
        
        // if while loop doesn't return anything , return {-1,-1}
        // start and end were already initialized with -1 -1
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
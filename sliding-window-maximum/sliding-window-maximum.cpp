class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> result;
        deque<int> dq;
        
        int i = 0,j = 0;
        
        while (j < nums.size()) {
          
            // storing element in dq in decreasing order
            // if last element of the dq is less than nums[j], pop the element
            while (dq.size() > 0 && dq.back() < nums[j]) {
                dq.pop_back();
            }   
            // push the element in the dq
            dq.push_back(nums[j]);
          
            // creating the window
            if (j - i + 1 < k) {
                j++;
            }
            // window is created
            else if (j - i + 1 == k) {
              
                // push the first element of  the dq(greatest) into the answer
                result.push_back(dq.front());
              
                // remove the first element of the window
                if (nums[i] == dq.front()) {
                    dq.pop_front();
                }
                // moving the window
                i++;
                j++;
            }
        }      
    
        return result;
    }
};
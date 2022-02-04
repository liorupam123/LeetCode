class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {        
        unordered_map<int, int> umap;
        int prefixSum = 0;
        umap[0] = -1; //save occurrence of zero as -1
        int ans = INT_MIN; //return this value
        
        for(int i=0; i<nums.size(); i++)
        {
            int val; //instead of modifying original constraints, consider element value in "val"
            
            if(nums[i] == 0)
                val = -1;
            
            else
                val = 1;
            
            prefixSum+=val;
            
            if(umap.find(prefixSum) == umap.end())
                umap[prefixSum] = i; //save first occurrence of prefixSum with value as currIdx
            
            else
            {
                int dist = i - umap[prefixSum];  //find the distance between current Index and first occurrence 
                if(dist > ans)
                    ans = dist;
            } 
        }
        
        if(ans == INT_MIN) //no 0's present or no 1's present in array
            return 0;
        
        else
            return ans;
    }
};

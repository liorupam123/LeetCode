// Hash Map Soln
// Time O(n.logn)
// Space O(n)

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        int n = nums.size();
      
        // taking an unordered_map to store the frequency
        // element and frequency
        unordered_map<int, int> mymap;
        for(int i=0;i<n;i++){
          mymap[nums[i]]++;
        }
        // vector of pair of element & frequency
        vector<pair<int,int>> p;
        
        // at first store the frequency then element as a pair in the vector
        for ( auto i : mymap ) {
            p.push_back(make_pair(i.second, i.first));
        }
        // sort the vector in decreasing order
        // it is sorted according to frequncy number
        sort(p.begin(), p.end(), greater<>());
        
        
        vector<int> res;
        // now iterate through the vector, and push the element (p.second) in the answer vector
        for ( int i=0; i<k; i++ ) {
            res.push_back(p[i].second);
        }
        // return the answer vector at the last
        return res;
    }
};
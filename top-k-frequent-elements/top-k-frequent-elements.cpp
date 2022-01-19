// Heaps Soln
// Time O(n.logk)
// Space O(n)

// comparator function for the priority queue
class CompareFunc{
public:
    bool operator() ( pair<int,int> n1, pair<int,int> n2 ) {
        return n1.second > n2.second;
    }
};

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
        // top k frequent -- kinda largest, so take a min heap
        // compare function to sort according to frequency
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareFunc> pq;
      
        // iterate through the map, and push the element and frequnency as a pair into the heap
        for ( auto i : mymap ) {
            pq.push(make_pair(i.first, i.second));
            // when heap size is > k ,pop the top element
            if ( pq.size() > k ) {
                pq.pop();
            }
        }
        
        vector<int> res;
      
        // while heap is not empty, push the pq.top.first (element) in the answer vector
        while ( !pq.empty() ) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        // return the answer vector at last
        return res;
    }
};
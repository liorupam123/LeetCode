class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0 , count = 0;
        for(int i=0;i<n;i++){
          maxi = max(maxi,arr[i]);
          if(i==maxi) count++;
        }
        return count;
    }
};
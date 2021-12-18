class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int index_sum = 0 , elements_sum = 0 , chunks =0;
        for(int i=0;i<n;i++){
          index_sum += i;
          elements_sum += arr[i];
          if(index_sum == elements_sum){
            chunks++;
          }
        }
        return chunks;
    }
};
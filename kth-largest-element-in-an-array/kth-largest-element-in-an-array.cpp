class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int n = a.size();
        // take a minheap, largest== minheap
        priority_queue <int, vector<int>, greater<int>> minheap; 
        for(int i=0;i<n;i++){
             // traverse the array and push element into maxheap
            minheap.push(a[i]);
             // when the size of the heap is greater than k,pop the top element
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        // return the top element, min heap store the min element at the end
        return minheap.top(); 
    }
};
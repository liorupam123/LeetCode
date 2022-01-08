class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int total_sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
         int n = cardPoints.size();
        
         if(k==n) return total_sum;
         
         int j = 0;
         int cur_sum=0;
         for(int i = 0; i<n-k; i++){
              cur_sum+=cardPoints[i];
         }
           
        int ans = -1;
        ans = max(ans, total_sum - cur_sum);
         for(int i=n-k; i<n; i++){
             cur_sum+=cardPoints[i];
             cur_sum-=cardPoints[j++];
             ans = max(ans, total_sum - cur_sum);
         }
        
        return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0 , j = n-1;
        while(i<j){
            int h = min(height[i],height[j]);
            int w = abs(i-j);
            int water = h * w;
            ans = max(ans,water);
            if(height[i]<height[j]) i++;
            else j--;
        }
        
        return ans;
    }
};
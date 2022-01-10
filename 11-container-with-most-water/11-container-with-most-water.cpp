class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int water = 0;
        while(i<j){
          // normal formula like brute force
          int heights = min(height[i],height[j]);
          int width = abs(i-j);
          water = max(water,heights*width);
          
          // its the main point
          // move the pointer of the less height
          if(height[i]<height[j]) i++;
          else  j--;
        }
        return water;
    }
};
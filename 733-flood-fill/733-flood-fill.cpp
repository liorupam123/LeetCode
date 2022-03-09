class Solution {
public:
    void floodFillRecursive(vector<vector<int>>& image, int sr,int sc,int n,int m,int source,int newColor){
      
        
        if(sr<0 || sr>=n || sc>=m || sc<0 || image[sr][sc]!=source) return;
      
        image[sr][sc] = newColor;
      
        floodFillRecursive(image,sr+1,sc,n,m,source,newColor);
        floodFillRecursive(image,sr-1,sc,n,m,source,newColor);
        floodFillRecursive(image,sr,sc+1,n,m,source,newColor);
        floodFillRecursive(image,sr,sc-1,n,m,source,newColor);
      
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(newColor==image[sr][sc]) return image;
      
        int n = image.size();
        int m = image[0].size();
        int source = image[sr][sc];
        
        floodFillRecursive(image,sr,sc,n,m,source,newColor);
        return image;
    }
};
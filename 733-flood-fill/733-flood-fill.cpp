class Solution {
public:
    void floodFillBFS(vector<vector<int>>& image, int sr,int sc,int n,int m,int source,int newColor){
      
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int curr_row = it.first;
            int curr_col = it.second;
            if(curr_row < 0 || curr_row>=n ||curr_col < 0 || curr_col >=m || image[curr_row][curr_col] != source ){
            continue;
            }
            
             // like number of island, change the source to new color
            image[curr_row][curr_col] = newColor;
          
            q.push({curr_row-1,curr_col});
            q.push({curr_row,curr_col+1});
            q.push({curr_row+1,curr_col});
            q.push({curr_row,curr_col-1});
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(newColor==image[sr][sc]) return image;
      
        int n = image.size();
        int m = image[0].size();
        int source = image[sr][sc];
        
        floodFillBFS(image,sr,sc,n,m,source,newColor);
        return image;
    }
};
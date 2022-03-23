class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &ans,vector<int> &currentpath,vector<bool> visited,int node,int n){
      
      
      if(node==n-1){
        ans.push_back(currentpath);
        //return;
      }
      if(visited[node]==true) return;
      
      visited[node] = true;
      
      for(auto it : graph[node]){
        
        //visited[it] = true;
        currentpath.push_back(it);
        dfs(graph,ans,currentpath,visited,it,n);
              currentpath.pop_back();
        
      }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> currentpath;
        
        vector<bool> visited(n+1,false);
        currentpath.push_back(0);
        dfs(graph,ans,currentpath,visited,0,n);
        return ans;
    }
};
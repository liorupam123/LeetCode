// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void recursivedfs(int node,vector<int> &ans,vector<bool> &visited,vector<int> adj[]){
        ans.push_back(node);
        visited[node] = true;
        for(auto x : adj[node]){
            if(visited[x] == false){
                recursivedfs(x,ans,visited,adj);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V+1,false);
        
        for(int node=0;node<V;node++){
            if(visited[node] == false){
                recursivedfs(node,ans,visited,adj);
            }
        }
        return ans;
    }
};

/*

1. At first make a vector to store all the nodes and a visited boolean vector with all false
2. Now iterate through all the vertex V
3. If the node is not visited, visited[node] == false, call the recursive function for the node
4. In the recursive function, push the node into ans vector --> ans.push_back(node)
5. Mark the node as visited --> visited[node] = true
6. Now call for his friends, if the adjacent nodes of the node are node visited, call recursion
for them. --> for(auto x : adj[node]){
            if(visited[x] == false){
                recursivedfs(x,ans,visited,adj);
            }
        }


*/

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
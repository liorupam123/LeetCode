/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void isfind(TreeNode* root, int x, int y,int level[2],int parent[2],int curlevel,TreeNode* curparent){
      
        if(root==NULL)  return;
        if(root->val == x){
            level[0] = curlevel;
            parent[0] = curparent->val;
        } 
        if(root->val == y){
              level[1] = curlevel;
              parent[1] = curparent->val;
        } 
      
        isfind(root->left,x,y,level,parent,curlevel+1,root);
        isfind(root->right,x,y,level,parent,curlevel+1,root);

    }
    bool isCousins(TreeNode* root, int x, int y) {
        int level[2]={-1,-1};
        int parents[2]={-1,-1};
      
        isfind(root,x,y,level,parents,0,new TreeNode (-1));
        if(level[0]==level[1]  && parents[0]!=parents[1]) return true;
        else  return false;
    }
};
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
    void dfs(TreeNode *root, int buff,int &ans){
        buff = buff*10 + root->val;
        if(!root->left && !root->right){
            ans += buff;
            return;
        }
        if(root->left) dfs(root->left, buff,ans);
        if(root->right) dfs(root->right, buff,ans);
    }
    int sumNumbers(TreeNode* root) {

        int buff = 0,ans=0;
        dfs(root, buff,ans);
        return ans;   

    }
};
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=minDepth(root->left);
        int rh=minDepth(root->right);
        // lh=0 means there is no left subtree,so we cannot compare its height to right subtree
        // return the height of the right subtree
        if(lh==0) return 1+rh; 
        // rh=0 means there is no right subtree, return the height of left subtree
        else if(rh==0) return 1+lh; 
        else return 1+ min(lh,rh);
    }
};
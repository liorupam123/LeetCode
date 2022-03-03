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
     void inorder(TreeNode* root, int L, int R,int &sum){
        if(root==NULL) return;
        if(root->left)  
          inorder(root->left, L, R,sum);
       
        if(root->val>=L && root->val<=R)  
          sum+=root->val;
       
        if(root->right)  
          inorder(root->right, L, R,sum);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        int sum = 0; 
        inorder(root, L, R,sum);
        return sum;
    }
};
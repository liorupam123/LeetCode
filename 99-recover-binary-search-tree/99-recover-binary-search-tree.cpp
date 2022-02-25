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

/* take a first and second and previous node as a null.
Now make a function to do inorder type traversal, go to left subtree, then check if the prev!=NULL && first==NULL  && prev->val >= root->val, first=prev and 
prev!=NULL && first!=NULL  && prev->val >= root->val, second=root
prev = root
go to right subtree 
call the function in main function and swap first->val,second->val
*/
class Solution {
    TreeNode *first = NULL, *second = NULL, *prev = NULL;
public:
    void recoverTree(TreeNode* root) {
        help(root);
        swap(first->val, second->val);
    }
    
    void help(TreeNode* root){
        if(root==NULL)  return;
        help(root->left);
        if(prev!=NULL && first==NULL && prev->val >= root->val)   first=prev;
        if(prev!=NULL && first!=NULL && prev->val >= root->val)   second=root;
        prev=root;
        help(root->right);
    }
};
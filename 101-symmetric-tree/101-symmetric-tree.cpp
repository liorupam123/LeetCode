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
    bool isSymmetric(TreeNode* root) {
      TreeNode* p = root->left;
      TreeNode* q = root->right;
         queue<TreeNode*> queue;
        if(p== NULL && q==NULL) return true;
        if(p== NULL || q==NULL) return false;
      
        queue.push(p); queue.push(q);
        while(!queue.empty())  {
            TreeNode* left = queue.front(); queue.pop();
            TreeNode *right = queue.front(); queue.pop();
            if(left==NULL && right==NULL) continue;
            if(left==NULL || right==NULL) return false;
            if(left->val != right->val) return false;
            queue.push(left->left);
            queue.push(right->right);
          
            queue.push(left->right);
            queue.push(right->left);
            
            
        }
        return true;  
    }
};
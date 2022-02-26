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

// take a queue and push node1 then node2
// in the while loop push node1->left and node2->left , then node1->right and node2->right
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
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
            queue.push(right->left);
            queue.push(left->right);
            queue.push(right->right);
        }
        return true;  
    }
};
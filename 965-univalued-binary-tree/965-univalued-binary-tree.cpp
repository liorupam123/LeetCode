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
    bool isUnivalTree(TreeNode* root) {
         if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int value = root->val;
        while(!q.empty()){
           
            int currentSize = q.size();
            for(int i=0;i<currentSize;i++){
            TreeNode *currentNode = q.front();
            q.pop();
            if(currentNode->val != value){
              return false;
            }
            if(currentNode->left!=NULL){
                q.push(currentNode->left);    
            }
             if(currentNode->right!=NULL){
                q.push(currentNode->right);    
            }
            }
        }
       return true;
    }
};
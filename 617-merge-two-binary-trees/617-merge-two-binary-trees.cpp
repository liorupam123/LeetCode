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

/* we will do preorder traversal to store the sum of two nodes into t1.
t1->value = t1->value and t2->value. Then go to node1's left and right. 
*/
class Solution {
public:
    TreeNode* merge(TreeNode* t1, TreeNode* t2){
      
        // if both null return 0
        if(t1==NULL && t2==NULL)  return 0; 
      
        // if one is null return another
        if(t1==NULL && t2!=NULL)  return t2; 
        if(t1!=NULL && t2==NULL)  return t1;
      
        // when two node node is not null make root1->val = root1->val + root2->val
        if(t1!=NULL && t2!=NULL){
            t1->val += t2->val;
        }  
        // recursively call the left-subtree and right-subtree of the sumnode
        t1->left = merge (t1->left, t2->left);
        t1->right = merge (t1->right, t2->right);
        
        // return the sum node
        return t1;
      
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1,t2);
    }
};
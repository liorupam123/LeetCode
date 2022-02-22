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

// if the node is null return from there nothing to add.

// Here we are maintaning a string currentPath, whenever we are moving to new node we are adding the root->val as a string in the currentPath.
// currentPath += to_string(root->val) + "->";

// whenever we are reaching the leaf node, thats mean we reach at the end of the tree, so we are adding the leaf node value in the currentPath and pushing the currentPath into the string vector.

/* if(root->left == NULL && root->right == NULL){
            currentPath += to_string(root->val);
            ans.push_back(currentPath);
            return;
        }
*/

// call the recusion function to the left and right subtree as normal.


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        rootToLeaf(root,"",ans);
        return ans;
    }
    
    void rootToLeaf(TreeNode *root,string currentPath,vector<string>&ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            currentPath += to_string(root->val);
            ans.push_back(currentPath);
            return;
        }
        
        currentPath += to_string(root->val) + "->";
        
        rootToLeaf(root->left,currentPath,ans);
        rootToLeaf(root->right,currentPath,ans);
        return;
    }
};


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
    TreeNode* sortedArrayToBST(vector<int>& nums){
        // take a left and right pointer for binary search
        int left = 0;
        int right = nums.size()-1;
        return createBST(nums,left,right);
    }
    
    TreeNode* createBST(vector<int> nums,int left,int right){  
        
        // creat a treenode as the root
        TreeNode* newroot;
        if(left <= right)
        {
            // find the middle and store as the node of the root
            int mid = left + (right-left) / 2;
            newroot = new TreeNode(nums[mid]);
            // set the node->left as --> left to mid-1
            // set the node->right as --> mid+1,right
            newroot->left = createBST(nums,left,mid-1);
            newroot->right = createBST(nums,mid+1,right);
            return newroot;
        }
        return NULL;
    }
};
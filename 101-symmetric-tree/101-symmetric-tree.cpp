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
    bool solve(TreeNode * r1, TreeNode * r2){
        // See the tree diagram are r1 and r2 null ? No, so this line dont execute
        if(r1 == NULL && r2 == NULL)
            return true; 
		
        // Is any one of r1 or r2 null ? Or are these values different ? No. Both values are
        // same so this else if wont execute either
        else if(r1 == NULL || r2 == NULL )
            return false; 
        
        // Now comes the main part, we are calling 2 seperate function calls 
        return (r1->val == r2->val) && solve(r1->left, r2->right) && solve(r1->right, r2->left);
        // First solve() before && will execute
        // r1->left is 3 and r2->right = 3
        // Both values are same , they will by pass both if and else if statement
        // Now again r1->left is null and r2->right is null
        // So they will return true from first if condtion
        // Now the scene is : we have executed first solve() before && and it has
        // returned us True so expression becomes ' return true && solve() '
        // Now solve after && will execute 
        // Similarly it will check for 4 and 4 , it will by pass if else statements
        // next time both will become null, so will return true
        // Thus 2nd solve() at the end will also hold true
        // and we know 'true && true' is true
        // so true will be returned to caller, and thus tree is mirror of itself.
        // Similarly you can check for any testcase, flow of execution will remain same.
        
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        // Imagine a tree:    1
        //                 2     2
        //               3   4 4   3
        // We are standing on root that is 1, function begins
        // and now r1 and r2 points to 2 and 2 respectively.                      
        return solve(root->left, root->right);     
    }
};

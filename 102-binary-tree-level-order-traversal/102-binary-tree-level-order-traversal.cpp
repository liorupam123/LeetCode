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

/* 
vector<vector<int>> is the final answer. At first take a queue and push the root in the queue. Then while queue is not empty, get the size of the queue, iterate and store the front of the queue as a node and pop from the queue. push the node's value into a temp vector. Now check for node's left and right. If they are not null, push the node-> left and node->right into the queue for next iteration. Now push the vector into the main answer.

*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        // take a queue
        queue<TreeNode*> q;
        // push the root at first
        q.push(root);
        while(!q.empty()) {
            // taking the size of the queue for every level
            int size = q.size();
            // this vector is storing the levels for vector<vector>> int
            vector<int> level;
            for(int i = 0;i<size;i++) {
                // taking the front of the queue as a node
                TreeNode *node = q.front();
                q.pop(); 
                // push the main node value into the level
                level.push_back(node->val); 
                //then checking it's left
                if(node->left != NULL) q.push(node->left);
                // checking it's right
                if(node->right != NULL) q.push(node->right); 
                
            }
            // push the level into the main answer
            ans.push_back(level); 
        }
        return ans; 
    }
};
//T.C — O(N) N == number of nodes
//S.C —  O(N) worst, for queue, it stores all the nodes
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // main result vector of vector
        vector<vector<int>> result; 
        if (root == NULL) {
            return result;
        }
        // 90% same code as level order traversal!
        // take a queue to store the node
        queue<TreeNode*> nodesQueue;
        // push the root at first.
        nodesQueue.push(root);
        
        // flag variable, true == left -> right , false == right -> left
        bool leftToRight = true; 
        
        
        // still queue is not empty
        while ( !nodesQueue.empty()) { 
            // take the size of the queue
            int size = nodesQueue.size();
            // level vector to store the nodes of every vector, and last push this to  main ans
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                // pop one by one... 9 then 20
                nodesQueue.pop(); 

                // find position to fill node's value
                // if true, then normal traversal, if false then reverse traversal
                int index = (leftToRight) ? i : (size - 1 - i); 
                
                // pushing the level wise value into the level answer
                row[index] = node->val;
                
                // go to left push the node into the queue and same for right
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after each level of traversal,
            // making the true to false , false to true.. after every trversal..
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};
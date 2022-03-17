class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stack;
        int res = 0;
        for (auto c : S) {
            if (c == '(') {
                stack.push(res);
                res = 0;
            }
            else {
                int prev = stack.top();
                stack.pop();
                res += prev + max(res, 1);
            }
        }
        return res;
    }
};
class Solution {
public:
    void reverseString(vector<char>& s) {
        _reverseString(s, 0, s.size() - 1);
    }
    void _reverseString(vector<char>& s, int start, int end){
        // Base Case
        if(start > end) return;
        swap(s[start++], s[end--]);
        // Recurrence relation
        _reverseString(s, start, end);
    }
};
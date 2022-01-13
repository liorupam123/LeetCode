class Solution {
public:
    static bool sort_by_end(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        //if (points.size() <= 1) return points.size();
        sort(points.begin(), points.end(), sort_by_end);
        int arrows = 1;
        vector<int> curr = points[0];
        for (auto balloon : points) {
            if (curr[1] < balloon[0]) {
                curr = balloon;
                arrows++;
            }
        }
        return arrows;
    }
};
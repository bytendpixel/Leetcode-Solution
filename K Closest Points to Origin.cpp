class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(), [](const auto &a, const auto &b){
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        return vector<vector<int>> (
            make_move_iterator(points.begin()),
            make_move_iterator(points.begin() + k)
        );
    }
};

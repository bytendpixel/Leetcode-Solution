#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle,
                      vector<int>& location) {
        vector<double> angles;
        int same = 0;
        int posx = location[0];
        int posy = location[1];

        for (const auto& point : points) {
            int xcoor = point[0] - posx;
            int ycoor = point[1] - posy;
            if (xcoor == 0 && ycoor == 0) {
                same++;
                continue;
            }
            double ang = atan2(ycoor, xcoor);
            angles.push_back(ang);
        }

        sort(angles.begin(), angles.end());

        // Handle circular case by adding 2*pi to each angle and concatenating
        int n = angles.size();
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + 2 * M_PI);
        }

        double view_rad = angle * M_PI / 180.0;
        int maxc = 0;
        int left = 0;

        for (int right = 0; right < angles.size(); right++) {
            while (angles[right] - angles[left] > view_rad) {
                left++;
            }
            maxc = max(maxc, right - left + 1);
        }

        return maxc + same;
    }
};

class Solution {
public:
    // using end_event_t = pair<int, pair<int, int>>;
    struct end_event_t {
        int x = 0;
        int y_bot = 0;
        int y_top = 0;

        end_event_t(int x, int y_bot, int y_top) : x(x), y_bot(y_bot), y_top(y_top) {};
    };

    struct compare_end_point {
        bool operator()(end_event_t const& a, end_event_t const& b) {
            if (b.x < a.x) { return true; }
            if (a.x < b.x) { return false; }
            return b.y_bot < a.y_bot;
        }
    };

    size_t compute_area(multiset<pair<int, int>> const& intervals, int x_range) {
        int linear_exposure = 0;
        for (auto it = intervals.begin(), it_end = intervals.end(); it != it_end; ) {
            auto interval = *it;
            for (++it; it != it_end && it->first <= interval.second; ++it) {
                interval.second = max(interval.second, it->second);
            }
            linear_exposure += size_t(interval.second - interval.first);
        }
        return size_t(linear_exposure) * size_t(x_range);
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end());
        priority_queue<end_event_t, vector<end_event_t>, compare_end_point> end_events;
        multiset<pair<int, int>> intervals;

        size_t total_area = 0;
        int prev_x = 0;

        // loop until there are both no more new rectangles AND no more endpoints
        for (size_t i = 0, i_end = rectangles.size(); i != i_end || !end_events.empty(); ) {
            int const x_start = [&end_events = std::as_const(end_events), &rectangles = std::as_const(rectangles), i, i_end]() {
                if (end_events.empty()) { return rectangles[i][0]; }
                if (i == i_end) { return end_events.top().x; }
                return min(rectangles[i][0], end_events.top().x);
            }();

            size_t const temp = compute_area(intervals, x_start - prev_x);
            total_area += temp;
            prev_x = x_start;

            // remove all end events and intervals for x position
            for (; !end_events.empty() && end_events.top().x == x_start; end_events.pop()) {
                intervals.erase(intervals.find({end_events.top().y_bot, end_events.top().y_top}));
            }

            // add all of the rectangles starting at x position
            for (; i != i_end && x_start == rectangles[i][0]; ++i) {
                int const x = rectangles[i][2];
                int const y_bot = rectangles[i][1];
                int const y_top = rectangles[i][3];
                end_events.push(end_event_t(x, y_bot, y_top));
                intervals.insert({y_bot, y_top});
            }
        }
        return total_area % 1000000007;
    }
};

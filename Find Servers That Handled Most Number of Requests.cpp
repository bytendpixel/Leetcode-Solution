#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:
    static std::vector<int> busiestServers(int k, const std::vector<int>& arrival, const std::vector<int>& load) {
        struct node {
            unsigned t;
            unsigned left_min;
            unsigned right_min;
        };

        std::vector<node> nodes (k + 1);

        for (auto [i, n] : nodes | std::views::enumerate) {
            n.t = 0;
            n.left_min = n.right_min = -(i & 1);
        }

        nodes[k].right_min = ~0u;

        auto left = [&] (unsigned i) {
            return (i | (i >> 1)) & (i - 1);
        };
        auto right = [&] (unsigned i) {
            i = i | left (i);

            while (i > k)
                i = left (i);

            return i;
        };
        auto left_ancestor = [&] (unsigned i) {
            return i & (i - 1);
        };
        auto right_ancestor = [&] (unsigned i) {
            return left_ancestor (i) + ((i ^ (i - 1)) + 1);
        };
        auto parent = [&] (unsigned i) {
            i = left_ancestor (i) | ((i ^ (i - 1)) + 1);

            if (i > k)
                i = left_ancestor (i);

            return i;
        };

        auto find = [&] (unsigned i, unsigned t) -> unsigned {
            while (i <= k) {
                node& n = nodes[i];

                if (n.t <= t)
                    return i;

                if (n.right_min <= t) {
                    i = right (i);

                    while (true) {
                        node& n = nodes[i];

                        if (n.left_min <= t)
                            i = left (i);
                        else if (n.t <= t)
                            return i;
                        else
                            i = right (i);
                    }
                } else {
                    i = right_ancestor (i);
                }
            }

            return 0;
        };

        std::vector<int> cnt (k + 1);
        int cnt_max = 0;

        unsigned c = 0;
        unsigned min_t = 0;

        for (auto [a, l] : std::views::zip (arrival, load)) {
            [&] {
                if (a < min_t)
                    return;

                const unsigned t = a + l;

                int i = find (c + 1, a);

                if (! i)
                    i = find (1, a);

                cnt_max = std::max (cnt_max, ++cnt[i]);

                node& n = nodes[i];

                n.t = t;

                unsigned last_min = std::min (
                    t,
                    std::min (n.left_min, n.right_min)
                );

                while (true) {
                    unsigned j = parent (i);

                    if (! j) {
                        min_t = last_min;

                        break;
                    }

                    node& p = nodes[j];

                    if (i < j) {
                        if (last_min != p.left_min)
                            p.left_min = last_min;
                        else
                            break;
                    } else {
                        if (last_min != p.right_min)
                            p.right_min = last_min;
                        else
                            break;
                    }

                    last_min = std::min (
                        p.t,
                        std::min (p.left_min, p.right_min)
                    );

                    i = j;
                }
            } ();

            ++c;
            c &= -(c != k);
        }

        cnt.erase (
            std::ranges::copy (
                cnt |
                std::views::drop (1) |
                std::views::enumerate |
                std::views::filter ([&] (const auto& t) {
                    return std::get<1> (t) == cnt_max;
                }) |
                std::views::keys,
                cnt.begin ()
            ).out,
            cnt.end ()
        );

        return cnt;
    }
};

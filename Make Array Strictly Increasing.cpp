struct ModifiedLIS {
  // key: right_value
  // value: longest length of sequence ending at the key.
  //
  // We initializes the data to have a single starting point.
  // All valid sequences must start here.
  std::map<pair<int, int>, int> lens = {{make_pair(1, -1), 0}};

  // Appends the specified object (two values) into the "array" and returns
  // the longest increasing subsequence ending at this new object.
  // Returns -1 if the argument object can not be added to any existing sequence.
  //
  // Each argument value is a pair of <index_score, num>
  int Append(pair<int, int> left_value, pair<int, int> right_value) {
    auto left_base = lens.lower_bound(left_value);
    if (left_base == lens.begin()) {
      return -1;  // We do not allow new sequence to start.
    }
    // cout << " - pre: [" << prev(left_base)->first.first << "," << prev(left_base)->first.second
    //     << "]," << prev(left_base)->second << endl;
    int len = std::prev(left_base)->second + 1;

    auto [right, inserted] = lens.insert({right_value, len});
    if (!inserted) {
      if (right->second >= len) {
        return len;
      }
      right->second = len;
    }
    for (auto it = std::next(right); it != lens.end() && it->second <= len;) {
      it = lens.erase(it);
    }
    return len;
  }
};

// Returns the length of longest fixable increasing subsequence of `nums`.
// Normally a subsequence is created by deleting some elements from the original array.
// A "fixable" increasing subsequence is that any deleted original elements can be
// instead substituted with elements from `subs` and it would still be an increasing sequence.
// Returns -1 if there is no such subsequence.
//
// For example:
//   `FixableLIS([1, 5, 6, 4], [2, 3])` returns 2, for the subsequence [1, 4].
//   It is fixable because we can substitute 5 with 2 and 6 with 3 to make [1, 2, 3, 4].
//   The longer increasing subsequence [1, 5, 6] is not fixable because we can't substitute
//   4 with elements from [2, 3] and still make a increasing sequence.
//
// REQUIRES: `subs` contains strictly increasing unique numbers.
int FixableLIS(const vector<int>& nums, const vector<int>& subs) {
  ModifiedLIS lis;
  int max_num = -1;
  for (int i = 0; i < nums.size(); ++i) {
    max_num = max(max_num, nums[i]);
    auto [lower, upper] = std::equal_range(subs.begin(), subs.end(), nums[i]);
    std::pair<int, int> left_value(lower - subs.begin() - i + 1, nums[i]);
    std::pair<int, int> right_value(upper - subs.begin() - i, nums[i]);
    // cout << "appending " << left_value.first << "," << left_value.second
    //     << " | " << right_value.first << "," << right_value.second << endl;
    int r = lis.Append(left_value, right_value);
    // cout << "  returned " << r << endl;
  }
  // We append an extra number at the end to ensure the sequence is "tail fixable".
  int tail = max(max_num, subs.back()) + 1;
  auto [lower, upper] = std::equal_range(subs.begin(), subs.end(), tail);
  std::pair<int, int> end_value(lower - subs.begin() - nums.size() + 1, tail);
  return lis.Append(end_value, end_value) - 1;
}

class Solution {
public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    std::sort(arr2.begin(), arr2.end());
    arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());
    int len = FixableLIS(arr1, arr2);
    return len >= 0 ? arr1.size() - len : -1;
  }
};

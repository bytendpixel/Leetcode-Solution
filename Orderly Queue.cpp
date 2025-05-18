class Solution {
public:
    string orderlyQueue(string s, int k) {

        int n = s.size();

        string p = s;
        sort(p.begin(), p.end());

        // string q = p.substr(0, k);
        // cout << "q : " << q << endl;

        // map<char, int> m;
        // for (char& c : q) m[c]++;

        // vector<int> a;
        // a.push_back(0);
        // string r;
        // for (int i = 0, j = 0; i < n; i++) {
        //     if (m[s[i]] > 0) {
        //         a.push_back(i);
        //         m[s[i]]--;
        //         j++;
        //     } else {
        //         r.push_back(s[i]);
        //     }
        // }

        if (k > 1) {
            // cout << "r : " << r << endl;
            // sort(r.begin(), r.end());
            // return (q + r);
            return p;
        }

        char c = p[0];

        int i = 0;
        for (; i < n; i++)
            if (s[i] == c) break;

        cout << "c: " << c << endl;
        cout << "i: " << i << endl;

        // int sum = s[i];
        string x = "";
        x += s[i];
        map<string, int> m2;
        // int mn = INT_MAX;
        // int mnI = 0;
        int prevI = i;
        i++;

        for (; i < n; i++) {
            if (s[i] == c) {
                // if (sum < mn) {
                //     mn = sum;
                //     mnI = prevI;
                // }
                m2[x] = min(m2.find(x) == m2.end() ? INT_MAX : m2[x], prevI);
                cout << "x : " << x << endl;
                // sum = s[i];
                x = "";
                x += s[i];
                prevI = i;
            } else {
                // sum += s[i];
                x += s[i];
            }
        }

        // if (sum < mn) {
        //     mn = sum;
        //     mnI = prevI;
        // }

        for (int j = 0; j < n; j++) {
            if (s[j] == c) break;
            else
                x += s[j];
        }

        m2[x] = min(m2.find(x) == m2.end() ? INT_MAX : m2[x], prevI);
        cout << "x : " << x << endl;

        pair<string, int> p2 = *m2.begin();
        int mnI = p2.second;

        cout << "mnI : " << mnI << endl;

        reverse(s.begin(), s.end());
        cout << s << endl;
        int len = s.size() - mnI;
        reverse(s.begin(), s.begin() + len);
        cout << s << endl;
        reverse(s.begin() + len, s.end());
        cout << s << endl;

        return s;

        // int f = 1;
        // int rotations = 0;
        // for (int i = 1; i < a.size(); i++) {
        //     if (f) {
        //         rotations += a[i] - a[i-1];
        //         f = 0;
        //     } else
        //         rotations += a[i] - a[i-1] - 1;
        // }

        // cout << "rotations : " << rotations << endl;
        // for (int& i : a) cout << i << " ";
        // cout << endl;

        // rotations %= r.size();
        // reverse(r.begin(), r.end());
        // reverse(r.begin(), r.begin() + r.size() - rotations);
        // reverse(r.begin() + r.size() - rotations, r.end());
        
        // string ans = q + r;
        // return ans;
        
    }
};

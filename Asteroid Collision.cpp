class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ast;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!s.empty() && asteroid < 0 && s.top() > 0) {
                if (s.top() < -asteroid) {
                    s.pop();  // Destroy the top positive asteroid
                } else if (s.top() == -asteroid) {
                    s.pop();  // Destroy both asteroids
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // The current asteroid is destroyed
                    break;
                }
            }

            if (!destroyed) {
                s.push(asteroid);  // Add the current asteroid if not destroyed
            }
        }

        while (!s.empty()) {
            ast.push_back(s.top());
            s.pop();
        }

        reverse(ast.begin(), ast.end());
        return ast;
    }
};

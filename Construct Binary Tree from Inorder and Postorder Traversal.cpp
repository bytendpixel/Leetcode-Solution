// struct TreeNode { int val; Node *left, *rite; Node(int x) : val(x), left(NULL), rite(NULL) {} };

using i32 = std::int32_t; // using f32 = std::float32_t;
using i64 = std::int64_t; // using f64 = std::float64_t;

static constexpr int N = 6000; 

int mapping[N + 1]{}, idx, n;

class Solution {
public:
    TreeNode* buildTree(const auto &inorder, const auto& posorder) {
        n = posorder.size() & inorder.size();

        for(const int &i: inorder) mapping[i + (N >> 1)] = &i - &inorder[0];
    	
    	idx = n - 1;
    	auto build = [&](auto&& build, int st, int en) -> TreeNode* {
    		if(st > en || en < st) return nullptr;
    		
    		int val = posorder[idx--];
    		TreeNode *t = new TreeNode(val);
    		
    		t->right = build(build, mapping[val + (N >> 1)] + 1, en);
            t->left  = build(build, st, mapping[val + (N >> 1)] - 1);
    		
            return t;
    	};
    	
        return build(build, 0, n - 1);
    }
};

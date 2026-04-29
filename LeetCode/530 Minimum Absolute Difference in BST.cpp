#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// vector解法 時O(nlogn) 空O(n)
class Solution {
public:
    vector<int> v;

    int getMinimumDifference(TreeNode* root) {
        add_value(root);
        int mini = 0x3f3f3f3f;
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); ++i){
            mini = min(abs(v[i] - v[i-1]), mini);
        }
        return mini;
    }

    void add_value(TreeNode* cur){
        v.push_back(cur->val);
        if(cur->left != nullptr) add_value(cur->left);
        if(cur->right != nullptr) add_value(cur->right);
    }
};

// inorder解法 時O(n) 空O(樹高)
class Solution2 {
public:
    int ans = 0x3f3f3f3f;
    TreeNode* prev = nullptr;

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode* cur){
        if(cur == nullptr) return;
        inorder(cur->left);

        if(prev != nullptr) ans = min(ans, cur->val - prev->val);
        prev = cur;

        inorder(cur->right);
    }
};
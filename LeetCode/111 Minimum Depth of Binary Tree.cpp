#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0; // empty tree
        if(root->left == nullptr && root->right == nullptr) return 1; // leaf node
        int ldepth = INF, rdepth = INF; // initially set to INF to prevent undefined value
        if(root->left != nullptr) ldepth = minDepth(root->left);
        if(root->right != nullptr) rdepth = minDepth(root->right);
        return min(ldepth, rdepth) + 1; // the smaller one plus myself
    }
};
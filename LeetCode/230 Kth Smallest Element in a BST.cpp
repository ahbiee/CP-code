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

class Solution {
public:
    // l < m < r
    int ans;
    int i;
    int kthSmallest(TreeNode* root, int k) {
        ans = 0 ;
        i = 0 ;
        inorder(root, k);
        return ans;
    }

    void inorder(TreeNode* cur, int k){
        if(cur->left != nullptr) inorder(cur->left, k);
        if(++i == k){
            ans = cur->val;
            return;
        }
        if(cur->right != nullptr) inorder(cur->right, k);
    }
};
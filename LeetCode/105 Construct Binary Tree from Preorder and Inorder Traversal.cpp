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

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) return nullptr;
        map<int, int> mp; // key: element number, value: its index in inorder, increase the speed to find root in inorder
        for(int i=0; i<preorder.size(); ++i) mp[inorder[i]] = i;
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }

    TreeNode* solve(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2, map<int, int>& mp){
        if(l1 > r1) return nullptr;
        TreeNode* curr = new TreeNode(preorder[l1]);
        if(l1 == r1) return curr;

        int index = mp[curr->val]; // current value's index in inorder
        curr->left = solve(preorder, l1+1, l1+index-l2, inorder, l2, index-1, mp);
        curr->right = solve(preorder, l1+index-l2+1, r1, inorder, index+1, r2, mp);
        return curr;
    }
};
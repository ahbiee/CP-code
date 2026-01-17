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

#define MAXN 105

TreeNode* q[MAXN]; // queue, bfs
int l, r;

class Solution {
public:
    // 判斷條件：
    // 1. 有右無左必為false
    // 2. 一旦遇到缺孩子的節點，接下來所有節點都必須是葉節點
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true; // 題目認為空樹是complete binary tree

        l = r = 0;
        q[r++] = root;
        bool leaf = false;
        TreeNode* curr;
        while(l < r){
            curr = q[l++];
            if(curr->left == nullptr && curr->right != nullptr) return false; // 條件1
            if(leaf && (curr->left != nullptr && curr->right != nullptr)) return false; // 條件2

            if(curr->left != nullptr) q[r++] = curr->left;
            if(curr->right != nullptr) q[r++] = curr->right;

            if(curr->left == nullptr || curr->right == nullptr) leaf = true;
        }
        return true;
    }
};
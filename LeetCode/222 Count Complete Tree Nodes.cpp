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
    int leftH(TreeNode* root){
        if(root==nullptr)return 0;
        return 1+leftH(root->left);
    }
    int rightH(TreeNode* root){
        if(root==nullptr)return 0;
        return 1+rightH(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int left=leftH(root);
        int right=rightH(root);
        if(left==right){
            return (int)pow(2,left)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
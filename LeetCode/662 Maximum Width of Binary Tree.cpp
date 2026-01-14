#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;
using pii = pair<int, int>;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define MAXN 3005
using ll = unsigned long long;
// 測資72是超級skewed tree，深度可以達到2^3000，要用unsigned long long存才不會超範圍

TreeNode* nodeq[MAXN];
ll indexq[MAXN];

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 1;
        int l = 0, r = 0;
        nodeq[r] = root;
        indexq[r++] = 1;

        while(l < r){
            ans = max(ans, indexq[r-1] - indexq[l] + 1);
            int size = r-l;
            for(int i=0; i<size; ++i){
                TreeNode* curr = nodeq[l];
                ll id = indexq[l++];
                if(curr->left != nullptr){
                    nodeq[r] = curr->left;
                    indexq[r++] = id*2;
                }
                if(curr->right != nullptr){
                    nodeq[r] = curr->right;
                    indexq[r++] = id*2+1;
                }
            }
        }
        return ans;
    }
};
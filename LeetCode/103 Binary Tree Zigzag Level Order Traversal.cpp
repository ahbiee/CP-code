#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define eb emplace_back
#define mp make_pair
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

#define MAXN 2005

TreeNode* q[MAXN];

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        int l = 0, r = 0;
        q[r++] = root;
        bool reverse = false;

        while(l < r){
            int size = r-l;
            vector<int> list;

            // 這邊有一點炫技，迴圈可以展開寫，只是這樣會比較簡潔
            // 也可以用102題的list遍歷法，確認reverse之後再決定是否要反序，再加入ans即可
            for(int i = reverse ? r-1 : l, j = reverse ? -1 : 1, k=0; k<size; i+=j, ++k){
                list.push_back(q[i]->val);
            }

            for(int i=0; i<size; ++i){
                TreeNode* curr = q[l++];
                if(curr->left != nullptr) q[r++] = curr->left;
                if(curr->right != nullptr) q[r++] = curr->right;
            }

            ans.push_back(list);
            reverse = !reverse;
        }
        return ans;
    }
};
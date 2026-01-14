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

// 經典BFS解法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        map<TreeNode*, int> mp;
        q.push(root);
        mp[root] = 0;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            int level = mp[curr];
            if(ans.size() == level) ans.push_back({});
            ans.at(level).push_back(curr->val);

            if(curr->left != nullptr){
                mp[curr->left] = level+1;
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                mp[curr->right] = level+1;
                q.push(curr->right);
            }
        }
        return ans;
    }
};

// 用陣列實作queue的優化BFS解法
#define MAXN 2005

TreeNode* q[2005];

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        int l = 0, r = 0; // head and tail index, take from head, add to tail
        q[r++] = root;
        while(l < r){ // !q.empty()
            int size = r-l;
            vector<int> list;
            for(int i=0; i<size; ++i){
                TreeNode* curr = q[l++]; // q.front(), q.pop();
                list.push_back(curr->val);
                if(curr->left != nullptr){
                    q[r++] = curr->left;
                }
                if(curr->right != nullptr){
                    q[r++] = curr->right;
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};
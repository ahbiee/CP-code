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

#define MAXN 10001

class Solution {
public:
    int tree[MAXN][26] = {};
    int passed[MAXN] = {};
    string end[MAXN] = {};
    int cnt = 1;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build(words);
        vector<string> ans;
        for(int i=0; i<board.size(); ++i)
            for(int j=0; j<board[0].size(); ++j)
                dfs(board, i, j, 1, ans);
        clear();
        return ans;
    }

    int dfs(vector<vector<char>>& board, int i, int j, int curr, vector<string>& ans){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 0) return 0;
        char tmp = board[i][j];
        
        int path = tmp - 'a';
        curr = tree[curr][path];
        if(passed[curr] == 0) return 0;

        int collected = 0;
        if(end[curr] != ""){
            ans.push_back(end[curr]);
            collected++;
            end[curr] = "";
        }
        board[i][j] = 0;

        collected += dfs(board, i + 1, j, curr, ans);
        collected += dfs(board, i - 1, j, curr, ans);
        collected += dfs(board, i, j + 1, curr, ans);
        collected += dfs(board, i, j - 1, curr, ans);

        board[i][j] = tmp;
        passed[curr] -= collected;
        return collected;
    }

    void build(vector<string>& words){
        cnt = 1;
        for(string word : words){
            int curr = 1;
            passed[curr]++;
            for(int i=0, path; i<word.length(); ++i){
                path = word[i] - 'a';
                if(tree[curr][path] == 0) tree[curr][path] = ++cnt;
                curr = tree[curr][path];
                passed[curr]++;
            }
            end[curr] = word;
        }
    }

    void clear(){
        for(int i=1; i<=cnt; ++i){
            for(int j=0; j<26; ++j){
                tree[i][j] = 0;
            }
            passed[i] = 0;
            end[i] = "";
        }
        cnt = 1;
    }
};
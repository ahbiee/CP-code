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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;

        int diff = 0;
        while(a != nullptr){
            a = a->next;
            diff++;
        }
        while(b != nullptr){
            b = b->next;
            diff--;
        }

        if(a != b) return nullptr;

        if(diff >= 0){
            a = headA;
            b = headB;
        }
        else{
            a = headB;
            b = headA;
        }
        diff = abs(diff);
        while(diff > 0){
            a = a->next;
            diff--;
        }
        while(a != b){
            a = a->next;
            b = b->next;
        }
        return a;
    }
};
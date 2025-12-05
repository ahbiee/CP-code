#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool cmp(ListNode* a, ListNode* b){
    return a->val > b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> heap(cmp);
        for(ListNode* node : lists){
            if(node != nullptr){
                heap.push(node);
            }
        }
        if(heap.empty()) return nullptr;

        ListNode* h = heap.top();
        heap.pop();
        ListNode* pre = h;
        if(pre->next != nullptr) heap.push(pre->next);

        while(!heap.empty()){
            ListNode* curr = heap.top();
            heap.pop();
            pre->next = curr;
            pre = curr;
            if(pre->next != nullptr) heap.push(pre->next);
        }

        return h;
    }
};
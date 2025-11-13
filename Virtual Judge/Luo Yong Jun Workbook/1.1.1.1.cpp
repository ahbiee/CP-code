#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        ListNode* head = nullptr, *current = nullptr, *last = nullptr;

        for(int i=1; i<=n; ++i){
            ListNode* newNode = new ListNode;
            newNode->val = i;
            newNode->next = nullptr;

            if(head == nullptr){
                head = newNode;
            }
            else{
                current->next = newNode;
            }
            current = newNode;
            last = newNode;
        }
        
        if(last != nullptr) last->next = head;

        bool first = true;
        while(head != head->next){
            if(first) first = false;
            else cout << ' ';

            ListNode *pre = nullptr;
            for(int i=1; i<m; ++i){
                pre = head;
                head = head->next;
            }
            cout << head->val;

            ListNode* tmp = head;
            head = head->next;
            pre->next = head;
            delete tmp;
            tmp = nullptr;
        }
        cout << ' ' << head->val << '\n';
        delete head;
        head = nullptr;
    }
    
    return 0;
}
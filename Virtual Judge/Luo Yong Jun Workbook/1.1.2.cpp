#include <bits/stdc++.h>
using namespace std;

struct listNode{
    int n;
    listNode* prev;
    listNode* next;
    listNode(int tag): n{tag}, prev{nullptr}, next{nullptr}{}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 用location和deleted的方法，空間換取時間，將每次O(n)的搜尋、存取改為O(1)
    vector<listNode*> locations(n+1);
    vector<bool> deleted(n+1, false);

    // 建造虛擬的頭、尾，他們不代表任何學生，只是一個指標
    listNode* head = new listNode(-1);
    listNode* tail = new listNode(-2);

    head->next = tail;
    tail->prev = head;

    // 處理第一位同學(不會被輸入)
    listNode* node1 = new listNode(1);
    head->next = node1;
    node1->prev = head;
    node1->next = tail;
    tail->prev = node1;
    locations[1] = node1;

    int k, p;
    for(int i=2; i<=n; ++i){
        cin >> k >> p;

        listNode* target = locations[k]; // 透過locations直接尋找到目標位置
        listNode* create = new listNode(i);
        locations[i] = create;

        if(p == 0){
            // 插入在左側
            listNode* prevNode = target->prev;
            prevNode->next = create;
            create->prev = prevNode;
            create->next = target;
            target->prev = create;
        }
        else{
            // 插入在右側
            listNode* nextNode = target->next;
            nextNode->prev = create;
            create->next = nextNode;
            create->prev = target;
            target->next = create;
        }
    
        /* 以下是原本的O(n)寫法，每次搜尋都要遍歷一遍
        if(k == head->n){
            // 如果我要插入的位置就是頭
            if(p == 0){
                // 在頭的左邊就直接插入，然後換新的頭
                create->next = head;
                head = create;
            }
            else{
                // 否則需要檢查頭的右邊的元素，然後傳遞關係
                listNode* tmp = head->next;
                head->next = create;
                create->next = tmp;
            }
        }
        else{
            // 否則我先找到我要插入的位置
            listNode* current = head;
            while(current->next->n != k) current = current->next; // 找到我要插入的位置的前一個
            if(p == 0){
                // 如果我要插在特定位置的前面，我要先儲存前一個的位置，以及目標位置
                listNode* prev = current;
                current = current->next;
                prev->next = create;
                create->next = current;
            }
            else{
                current = current->next; //因為插在右邊所以我走到該特定位置
                listNode* tmp = current->next;
                current->next = create;
                create->next = tmp;
            }
        }
        */
    }

    int m;
    cin >> m;
    int rm;
    while(m--){
        cin >> rm;

        if(deleted[rm]) continue;
        deleted[rm] = true;

        listNode* toDelete = locations[rm];

        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;

        // CP中可以不delete節點以節省時間

        /* 以下是原本的O(n)刪除
        if(head != nullptr && head->n == rm){
            listNode* toDelete = head;
            head = head->next;
            delete toDelete;
            continue;
        }

        if(head == nullptr) continue;

        listNode* current = head;
        while(current->next != nullptr && current->next->n != rm) current = current->next; // 找到我要刪除的位置的前一個節點
        if(current->next == nullptr) continue;
        listNode* prev = current; // 前prev 中current 後tmp ， 要刪除current
        current = current->next;
        listNode* tmp = current->next;
        prev->next = tmp;
        delete current;
        */
    }

    bool first = true;
    listNode* current = head->next;
    while(current != tail){
        if(!first) cout << ' ';
        first = false;
        cout << current->n;
        current = current->next;
    }
    return 0;
}
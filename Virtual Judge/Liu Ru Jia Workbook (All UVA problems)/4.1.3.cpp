#include <bits/stdc++.h>
using namespace std;

// 這題也可以用陣列做(arr + visited)，但我想試試看linked list

struct Node{
    Node(int i) : n{i} {}
    int n;
    Node* l = nullptr;
    Node* r = nullptr;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m; // n people, k for ccw pace(right), m for cw pace(left)

    while(cin >> n >> k >> m){
        if(n == 0 && k == 0 && m == 0) break;
        Node* head = new Node(1);
        Node* prev = head;
        for(int i=2; i<=n; ++i){
            Node* curr = new Node(i);
            curr->l = prev;
            prev->r = curr;
            prev = curr;
        }
        head->l = prev;
        prev->r = head;

        Node* right = head, *left = prev; // right: 1-2-3-4 left: 10-9-8

        bool flag = false;
        int remain = n;
        while(remain > 0){
            if(flag) printf(",");
            flag = true;

            for(int i=1; i<k; ++i) right = right->r; // run k-1 times (counts the original position)
            for(int i=1; i<m; ++i) left = left->l; // run m-1 times
            
            Node* pk = right;
            Node* pm = left;

            if(pk == pm){
                printf("%3d", pk->n);
                Node* next = pk->r;
                pk->r->l = pk->l;
                pk->l->r = pk->r;
                delete pk;

                right = next;
                left = next->l;
                remain--;
            }
            else{
                printf("%3d%3d", pk->n, pm->n);
                Node* nextR = pk->r;
                Node* nextL = pm->l;

                pk->r->l = pk->l;
                pk->l->r = pk->r;

                pm->r->l = pm->l;
                pm->l->r = pm->r;

                right = nextR;
                if(right == pm) right = pm->r;

                left = nextL;
                if(left == pk) left = pk->l;

                delete pk;
                delete pm;
                remain -= 2;
            }
        }
        puts("");
    }

    return 0;
}

// 結果用linked list是自作孽 好難啊
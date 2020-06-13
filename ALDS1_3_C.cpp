#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
#include<queue>
#include<map>

using namespace std;

struct Node {
    long long int key;
    Node *prev, *next;
};

Node* nil;

Node* search(long long int x){
    Node* pNode = nil->next;

    while(pNode != nil && pNode->key != x){
        pNode = pNode->next;
    }

    return pNode;   
}
void init(){
    nil = new Node;
    nil->next = nil;
    nil->prev = nil; // 自分自身を指す
}
void insert(long long int x){
    Node *pNode = new Node;
    pNode->key = x;

    // 番兵の直後にノードを追加
    pNode->next = nil->next;
    pNode->prev = nil;
    nil->next->prev = pNode;
    nil->next = pNode;
}
void del(Node* t){
    if(t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}
void delFirst(){
    del(nil->next);
}
void delLast(){
    del(nil->prev);
}
void delKey(long long int key){
    del(search(key));
}



int main(){
    long long int n;
    cin >> n;
    string com;
    int key;
    init();
    long long int sum = 0;
    for(int i=0;i<n;i++){
        cin >> com;

        if(com == "insert") {
            cin >> key;
            insert(key);
            sum++;
        }
        if(com == "delete") {
            cin >> key;
            delKey(key);
            sum--;
        }
        if(com == "deleteFirst") {
            delFirst();
            sum--;
        }            
        if(com == "deleteLast") {
            delLast();
            sum--;
        }
    }

    Node* pNode = nil->next;
    int cnt = 0;
    while(true){
        if(pNode == nil) break;
        if(cnt++ > 0) cout << " ";
        cout << pNode->key;
        pNode = pNode->next;
    }
    cout << endl;
}

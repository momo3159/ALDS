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
const int MAX = 200;

class Stack {
    private:
        int S[MAX] = {0};
        int sp = -1;

    public:
        void init();
        void push(int x);
        int pop();
        bool isEmpty();
        bool isFull();
};

void Stack::init(){
    sp = -1;
}

void Stack::push(int x){
    if(isFull()){
        sp++;
        S[sp] = x;
    } else {
        cout << "入れられません" << endl;
        return;
    }
}

int Stack::pop(){
    if(isEmpty()){
        int retval = S[sp];
        sp--;
        return retval;
    } else {
        cout << "中身がありません" << endl;
        return NULL;
    }
}

bool Stack::isEmpty(){
    if(sp  >=  0) return true;
    else return false;
}

bool Stack::isFull(){
    if(sp+1 < MAX) return true;
    else {
        cout << "オーバーフロー" << endl;
        return false;
    }
}


int main(){
    Stack stack;

    int a, b;
    char input[100];

    while(scanf("%s", input) != EOF){
        switch (input[0]){
            case '+':
                a = stack.pop();
                b = stack.pop();
                stack.push(a+b);
                break;
            case '-':
                a = stack.pop();
                b = stack.pop();
                stack.push(b-a);
                break;
            case '*':
                a = stack.pop();
                b = stack.pop();
                stack.push(a*b);
                break;
            default:
                stack.push(atoi(input));
                break;
        }
    }

    cout << stack.pop() << endl;
}

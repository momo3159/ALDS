#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
#include<map>

using namespace std;
const int MAX = 1000000;

class Queue {
    private:
        int q[MAX];
        int head = 0;
        int tail = 0;

    public:
        void init();
        void enqueue(process x);
        process dequeue();
        bool isFull();
        bool isEmpty();
};

void Queue::init(){
    head = tail = 0;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout << "入れられません" << endl;
        return;
    } else {
        q[tail] = x;
        if(tail == MAX - 1) tail = 0;
        else tail++;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        cout << "キューは空です" << endl;
        return NULL;
    } else {
        int retval = q[head];
        if(head == MAX-1) head = 0;
        else  head++;
        
        return retval;
    }
}

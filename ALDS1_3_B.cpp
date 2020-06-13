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
const int MAX = 1000000;

struct process {
    string name;
    int time;
};

class Queue {
    private:
        process q[MAX];
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

void Queue::enqueue(process x){
    if(isFull()){
        cout << "入れられません" << endl;
        return;
    } else {
        q[tail] = x;
        if(tail == MAX - 1) tail = 0;
        else tail++;
    }
}

process Queue::dequeue(){
    if(isEmpty()){
        process error;
        error.name = "error";
        error.time = NULL;
        cout << "キューは空です" << endl;
        return error;
    } else {
        process retval = q[head];
        if(head == MAX-1) head = 0;
        else  head++;
        
        return retval;
    }
}

bool Queue::isFull(){
    return head == (tail+1)%MAX;
}

bool Queue::isEmpty() {
    return head == tail;
}



int main(){
    int n, q;
    cin >> n >> q;
    int sum_time = 0;

    Queue queue;
    process tmp;
    vector<process> p(n);
    for(int i=0;i<n;i++) {
        cin >> p[i].name >> p[i].time;
        queue.enqueue(p[i]);
    }

    while(!queue.isEmpty()){
        tmp = queue.dequeue();

        if(tmp.time > q){
            sum_time += q;
            tmp.time -= q;
            queue.enqueue(tmp);
        } else {
            sum_time += tmp.time;
            cout << tmp.name << " " << sum_time << endl;
        }
    }
}

//
//  main.cpp
//  queue_2
//
//  Created by 村上候助 on 2017/10/04.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>
#define LEN 100000

using namespace std;

struct P {
    char name[10];
    int t;
};

P process[LEN];
int head, tail;

void enqueue(P x){
    process[tail] = x;
    tail = (tail+1)%LEN;
}

P dequeue(){
    P x = process[head];
    head = (head + 1) % LEN;
    return x;
}

int min(int a, int b){return a < b ? a : b;}

int main(int argc, const char * argv[]) {
    int elaps = 0;
    int c, i, n, q;
    P u;
    scanf("%d %d", &n, &q);
    for (i = 0; i < n; i++){
        scanf("%s %d", process[i].name, &process[i].t);
    }
    head = 0; tail = n;
    
    while(head!=tail){
        u = dequeue();
        c = min(q, u.t);
        u.t -= c;
        elaps += c;
        if(u.t > 0) enqueue(u);
        else{
            cout << u.name << " " << elaps << endl;;
        }
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}

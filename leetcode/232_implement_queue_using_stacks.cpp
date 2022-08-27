#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int n;

    MyQueue() {
        n = 0;
    }
    
    void push(int x) {
        s1.push(x); 
        n++;
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int y = s1.top();
                s1.pop();
                s2.push(y);
            }
        }
        int x = s2.top();
        s2.pop();
        n--; 
        return x;
    }
    
    int peek() {
        if (s2.empty()) {  // Case that there are were only pushes, no pops.
            while (!s1.empty()) {
                int y = s1.top();
                s1.pop();
                s2.push(y);
            }
        }
        int x = s2.top();
        return x;
    }
    
    bool empty() {
        return n == 0;
    }
};

int main() {
    MyQueue q = MyQueue();
    q.push(1);
    q.push(2);
    q.pop();
    q.peek();
}
#include<iostream>

using namespace std;

class Stack {
    int* stack;
    int index;
    int capacity;    
public:
    Stack() {
        this->capacity = 5;
        this->index = -1;
        this->stack = new int[capacity];
    }

    ~Stack() {
        delete this->stack;
    }

    int getCapacity() {
        return this->capacity;
    }

    void push(int value);
    int pop();
    int top();
    bool isEmpty();
};

void Stack::push(int value) {
    if(index == capacity-1) {
        capacity += 5;
        int n[capacity];
        for(int i=0; i<=index; i++) {
            n[i] = this->stack[i];
        }
        delete this->stack;
        this->stack = n;
    }
    this->stack[++index] = value;
}

int Stack::pop() {
    if(index > -1) {
        return this->stack[index--];
    }
}

int Stack::top() {
    return this->stack[index];
}

bool Stack::isEmpty() {
    return this->index == -1 ? true : false;
}

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(s.isEmpty() == false) {
        cout << s.pop() << " ";
    }

    return 0;
}
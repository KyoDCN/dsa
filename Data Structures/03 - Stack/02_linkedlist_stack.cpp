#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }

    ~Node() {
        delete this->next;
    }
};

class Stack {
    Node* stack;
    int size;
public:
    Stack() {
        this->stack = NULL;
        size = 0;
    }

    int getSize() {
        return this->size;
    }

    void push(int value);
    int pop();
    int top();
    bool isEmpty();
};

void Stack::push(int value) {
    if(this->stack == NULL) {
        this->stack = new Node(value);
    } {
        Node* new_node = new Node(value);
        new_node->next = this->stack;
        this->stack = new_node;
    }
    
    this->size++;
}

int Stack::pop() {
    if(isEmpty()) return -1;

    Node* temp = this->stack;
    this->stack = this->stack->next;
    int value = temp->data;
    this->size--;
    return value;
}

int Stack::top() {
    return this->stack->data;
}

bool Stack::isEmpty() {
    return this->size == 0 ? true : false;
}


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    return 0;
}
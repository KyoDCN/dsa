#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }

    ~Node() {
        delete this->next;
    }
};

class Queue {
    Node* head;
    Node* tail;
    int size;
public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    ~Queue() {
        delete head;
    }

    int getSize() {
        return this->size;
    }

    void push(int value);
    int pop();
    int front();
    int back();
    bool isEmpty();
    void reverse();
};

void Queue::push(int value) {
    if(this->head == NULL) {
        this->head = new Node(value);
        this->tail = head;
        this->size++;
        return;
    }

    this->tail->next = new Node(value);
    this->tail = this->tail->next;
    this->size++;
}

int Queue::pop() {
    if(isEmpty()) {
        return -1;
    }

    Node* temp = this->head;
    this->head = this->head->next;
    int value = temp->value;
    temp->next = NULL;
    delete temp;

    this->size--;

    return value;
}

int Queue::front() {
    return this->tail->value;
}

int Queue::back() {
    return this->head->value;
}

bool Queue::isEmpty() {
    return this->size == 0 ? true : false;
}

void Queue::reverse() {
    Node* prev = NULL;
    Node* next;
    Node* curr = this->head;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    this->tail = this->head;
    this->head = prev;
}

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.isEmpty()) {
        cout << q.pop() << " ";
    }

    return 0;
}
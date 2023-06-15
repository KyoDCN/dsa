#include<iostream>

using namespace std;

class Queue {
    int* queue;

    int capacity;
    int size;
    int s_index;
    int e_index;
public:
    Queue() {
        this->capacity = 5;
        this->size = 0;
        this->s_index = 0;
        this->e_index = 0;
        
        this->queue = new int[capacity];
    }

    ~Queue() {
        delete this->queue;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }

    void push(int value);
    int pop();
    int front();
    int back();
    bool isEmpty();
};

void Queue::push(int value) {
    // if size exceeds capacity, dynamically allocate more space
    if(size == capacity) {
        int* old_arr = this->queue;
        this->queue = new int[capacity+5];

        for(int i=0; i<this->capacity; i++) {
            this->queue[i] = old_arr[this->s_index++];

            // if start index == capacity, move start index back to 0
            if(this->s_index == this->capacity) {
                this->s_index = 0;
            }
        }

        // Reset all indexers
        this->s_index = 0;
        this->e_index = this->capacity;
        this->capacity += 5;
    }

    this->queue[e_index] = value;

    this->e_index++;
    this->size++;

    // Move end index to 0 if it exceeds array range
    if(this->e_index == this->capacity) {
        this->e_index = 0;
    }
}

int Queue::pop() {
    if(size == 0) return -1;

    int value = this->queue[this->s_index++];
    this->size--;

    // reset start index back to 0 if it hits capacity range
    if(s_index == this->capacity) {
        this->s_index = 0;
    }

    return value;
}

int Queue::front() {
    return this->queue[s_index];
}

int Queue::back() {
    return this->queue[e_index-1];
}

bool Queue::isEmpty() {
    return this->size == 0 ? true : false;
}

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.push(6);
    q.pop();
    q.push(7);
    q.pop();
    q.push(8);


    while(!q.isEmpty()) {
        cout << q.pop() << " ";
    }    

    return 0;
} 
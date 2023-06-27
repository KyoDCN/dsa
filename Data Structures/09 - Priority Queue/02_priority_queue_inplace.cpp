#include<iostream>
#include<vector>

using namespace std;

class PriorityQueue {
    int* pq;
    int capacity;
    int size;

    void compare(int current_child_index);
    void downheapify(int current_parent_index);
public:
    PriorityQueue() {
        capacity = 5;
        size = 0;
        pq = new int[capacity];
    }

    ~PriorityQueue() {
        delete pq;
    }

    void insert(int value);
    void removeMin();
    int getMin();
    int getLastOfArray();
    bool isEmpty();
    int getSize();
    void print();
};

void PriorityQueue::compare(int current_child_index) {
    while(current_child_index > 0) {
        int parent_index = (current_child_index-1)/2;

        if(pq[parent_index] > pq[current_child_index]) {
            swap(pq[parent_index], pq[current_child_index]);
        }

        current_child_index = parent_index;
    }
}

void PriorityQueue::downheapify(int current_parent_index) {
    while(true) {
        int left_child_index = (2*current_parent_index)+1;
        int right_child_index = (2*current_parent_index)+2;

        int min_child_index = current_parent_index;

        // Compare Left Child value to Parent value
        if(left_child_index < size) {
            if(pq[left_child_index] < pq[current_parent_index]) {
                min_child_index = left_child_index;
            }
        }

        // Compare Right Child value to Left Child value
        if(right_child_index < size) {
            if(pq[right_child_index] < pq[left_child_index]) {
                min_child_index = right_child_index;
            }
        }

        // Break if parent value is less than child value
        if(current_parent_index == min_child_index) break;

        // Otherwise, swap parent and child
        swap(pq[current_parent_index], pq[min_child_index]);

        // Set child index as the new parent index
        current_parent_index = min_child_index;
    }
}

void PriorityQueue::insert(int value) {
    if(size == capacity) {
        int* old_array = this->pq;

        this->capacity += 5;
        pq = new int[capacity];
        
        for(int i=0; i<size; i++) {
            pq[i] = old_array[i];
        }

        delete[] old_array;
    }
    
    pq[size++] = value;
    compare(size-1);
}

void PriorityQueue::removeMin() {
    swap(pq[0], pq[this->size-1]);
    size--;
    downheapify(0);
}

int PriorityQueue::getMin() {
    return pq[0];
}

bool PriorityQueue::isEmpty() {
    return this->size == 0;
}

int PriorityQueue::getSize() {
    return this->size;
}

int PriorityQueue::getLastOfArray() {
    return pq[this->size-1];
}

int main() {
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(1);
    pq.insert(9);
    pq.insert(2);
    pq.insert(8);
    pq.insert(3);
    pq.insert(7);
    pq.insert(4);
    pq.insert(6);
    pq.insert(5);

    while(!pq.isEmpty()) {
        cout << pq.getMin() << " ";
        pq.removeMin();
    }
    return 0;
}
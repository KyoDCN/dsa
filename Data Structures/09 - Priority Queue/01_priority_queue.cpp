#include<iostream>
#include<vector>

using namespace std;

class PriorityQueue {
    vector<int> pq;
    void compare(int current_child_index);
    void downheapify(int current_parent_index);
public:
    void insert(int value);
    void removeMin();
    int getMin();
    int getLastOfArray();
    bool isEmpty();
    int getSize();
    void print();
};

void PriorityQueue::compare(int current_child_index) {
    if(current_child_index <= 0) return;
    
    int parent_index = (current_child_index-1)/2;

    if(pq[parent_index] > pq[current_child_index]) {
        swap(pq[parent_index], pq[current_child_index]);
    }

    compare(parent_index);
}

void PriorityQueue::downheapify(int current_parent_index) {
    if(current_parent_index > pq.size()) return;

    int left_child_index = (2*current_parent_index)+1;
    int right_child_index = (2*current_parent_index)+2;

    int minimum_child_index = current_parent_index;

    if(left_child_index < pq.size()) {
        if(pq[left_child_index] < pq[current_parent_index]) {
            minimum_child_index = left_child_index;
        }
    } 

    if(right_child_index < pq.size()) {
        if(pq[right_child_index] < pq[left_child_index]) {
            minimum_child_index = right_child_index;
        }
    }

    if(current_parent_index == minimum_child_index) return;

    swap(pq[current_parent_index], pq[minimum_child_index]);

    downheapify(minimum_child_index);
}

void PriorityQueue::insert(int value) {
    pq.push_back(value);

    compare(pq.size()-1);
}

void PriorityQueue::removeMin() {
    swap(pq[0], pq[pq.size()-1]);
    pq.pop_back();
    downheapify(0);
}

int PriorityQueue::getMin() {
    return pq[0];
}

int PriorityQueue::getLastOfArray() {
    return pq[getSize()-1];
}

void PriorityQueue::print() {
    for(auto x : pq) {
        cout << x << " ";
    }
    cout << endl;
}

int PriorityQueue::getSize() {
    return pq.size();
}

bool PriorityQueue::isEmpty() {
    return pq.empty();
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
    while(!pq.isEmpty()) {
        cout << pq.getMin() << " ";
        pq.removeMin();
    }

    return 0;
}
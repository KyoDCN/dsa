#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        delete this->next;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        this->head = NULL;
    }

    Node* setHead(Node* node) {
        this->head = node;
    }
    Node* getHead() {
        return this->head;
    }

    void insert(int value);
    void insert(int value, int ith);
    void remove(int ith);
    void remove_nth_from_last(int nth);
    void print();
    void print(int ith);
    int search(int value);
    int middle();
    void reverse_list();
    Node* reverse_list(Node* n);
    int length();
};

int LinkedList::length() {
    if(this->head == NULL) return 0;
    
    Node* curr = this->head;
    int l{0};
    while(curr != NULL) {
        curr = curr->next;
        l++;
    }

    return l;
}

void LinkedList::print() {
    if(this->head == NULL) return;

    Node* curr = this->head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void LinkedList::print(int ith) {
    Node* curr = this->head;

    int counter = ith;
    while(counter--) {
        curr = curr->next;
    }

    cout << ith << " ith value: " << curr->data << endl;
}

int LinkedList::search(int value) {
    if(this->head == NULL) return -1;

    Node* curr = this->head;
    int index{0};
    while(curr) {
        if(curr->data == value) return index;
        index++;
        curr = curr->next;
    }

    return -1;
}

void LinkedList::insert(int value) {
    if(this->head == NULL) {
        this->head = new Node(value);
        this->head->next = NULL;
        return;
    }

    Node* curr = this->head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new Node(value);
    curr->next->next = NULL;
}

void LinkedList::insert(int value, int ith) {
    if(this->head == NULL) return;

    Node* curr = this->head;
    for(int i=1; i<ith; i++) {
        curr = curr->next;
        if(curr == NULL) return;
    }

    if(ith == 0) {
        Node* new_node = new Node(value);
        new_node->next = this->head;
        this->head = new_node;
    } if(curr->next == NULL) {
        curr->next = new Node(value);
        curr = curr->next;
        curr->next = NULL;
    } else {
        Node* temp = curr->next;
        curr->next = new Node(value);
        curr = curr->next;
        curr->next = temp;
    }
}

void LinkedList::remove(int ith) {
    if(this->head == NULL) return;

    if(ith == 0) {
        Node* temp = this->head;
        this->head = this->head->next;
        temp->next = NULL;
        delete temp;
        return;
    }


    Node* curr = this->head;
    for(int i=1; i<ith; i++) {
        curr = curr->next;
        if(curr == NULL) return;
    }

    if(curr->next == NULL) {
        delete curr;
        curr = NULL;
    } else {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = NULL;
        delete temp;
    }
}

void LinkedList::remove_nth_from_last(int nth) {
    if(this->head == NULL) return;

    Node* curr = this->head; // Slow
    Node* leading = this->head->next; // Fast

    while(nth--) {
        if(leading == NULL && nth > 0) return; // If leading is null, and nth counter still remaining, means ith is beyond head node

        leading = leading->next;
    }

    if(leading == NULL) { // if nth is 0, and leading is null, then curr would be on head node
        Node* temp = this->head;
        this->head = this->head->next;
        temp->next = NULL;
        delete temp;
        temp = NULL;
        return;
    }

    while(leading && leading->next) {
        leading = leading->next;
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    temp->next = NULL;
    delete temp;
    temp = NULL;
}
 
int LinkedList::middle() {
    Node* slow = this->head;
    Node* fast = this->head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

void LinkedList::reverse_list() {
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = this->head;

    while(curr) {
        next = curr->next; // Store next node before we disconnect
        curr->next = prev; // Redirect curr->next to prev node
        prev = curr; // Set prev node to curr node
        curr = next; // Set curr to the stored next node
    }

    this->head = prev;
}

Node* LinkedList::reverse_list(Node* prev) {
    if(prev->next == NULL) {
        this->head = prev;
        return prev;
    }

    Node* curr = reverse_list(prev->next);
    prev->next = NULL;
    curr->next = prev;
    return prev;
}

// External Functions

// Iterative Form
Node* merge_sort(Node* node) {
    if(node->next == NULL) return node;

    Node* h1{node}; // LL 1
    Node* h2; // LL 2

    // Determine Mid
    Node* slow = h1;
    Node* fast = h1->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    h2 = slow->next;
    slow->next = NULL;
    
    // Run left and right nodes through merge sort
    Node* result1 = merge_sort(h1);
    Node* result2 = merge_sort(h2);

    Node* merged_head{NULL};
    Node* merged;

    // Determine head for merged list
    if(result1->data < result2->data) {
        merged_head = result1;
        result1 = result1->next;
    } else {
        merged_head = result2;
        result2 = result2->next;
    }

    merged = merged_head;

    // Sort remaining list items
    while(result1 && result2) {
        if(result1->data < result2->data) {
            merged->next = result1;
            result1 = result1->next;
        } else {
            merged->next = result2;
            result2 = result2->next;
        }
        merged = merged->next;
    }

    if(result1) {
        merged->next = result1;
    }
    
    if(result2) {
        merged->next = result2;
    }

    return merged_head;
}

// Recursive Form
Node* merge_sort2(Node* l, Node* r) {
    if(l == NULL) {
        return r;
    }

    if(r == NULL) {
        return l;
    }

    Node* curr;
    if(l->data < r->data) {
        curr = l;
        curr->next = merge_sort2(l->next, r);
    } else {
        curr = r;
        curr->next = merge_sort2(l, r->next);
    }

    return curr;
}

Node* merge_sort2(Node* node) {
    if(node->next == NULL) return node;

    Node* h1 = node;
    Node* h2;

    Node* slow = h1;
    Node* fast = h1->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    h2 = slow->next;
    slow->next = NULL;

    Node* r1 = merge_sort2(h1);
    Node* r2 = merge_sort2(h2);

    return merge_sort2(r1, r2);
}

int main() {
    LinkedList l;
    l.insert(9);
    l.insert(1);
    l.insert(8);
    l.insert(2);
    l.insert(7);
    l.insert(3);
    l.insert(6);
    l.insert(4);
    cout << "Length of LL is: " << l.length() << endl;
    l.print();
    Node* h = merge_sort2(l.getHead());
    l.setHead(h);
    l.print();
}
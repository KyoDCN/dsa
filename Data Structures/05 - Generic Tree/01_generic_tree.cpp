#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;

    Node(int data) {
        this->data = data;
    }

    ~Node() {
        for(auto x : this->children) {
            delete x;
        }
    }
};

class GenericTree {
    Node* root;
    int size(Node* curr);
    int height(Node* curr);
    int leafNodeCount(Node* curr);

    void printLevelOrder(Node* curr);
    void printPreTraversal(Node* curr);
    void printPostTraversal(Node* curr);
    void printKLevel(Node* curr, int k);
public:
    GenericTree() {
        this->root = NULL;
    }

    int size();
    int height();
    int leafNodeCount();

    void createTree();
    void deleteTree();

    void print();
    void printLevelOrder();
    void printPreTraversal();
    void printPostTraversal();
    void printKLevel(int k);
};

void GenericTree::createTree() {
    queue<Node*> q;

    int value;
    cout << "Enter value: ";
    cin >> value;
    cout << endl;

    this->root = new Node(value);
    q.push(this->root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int numChildren;
        cout << "Enter number of children for parent " << curr->data << ": ";
        cin >> numChildren;
        cout << endl;

        for(int i=0; i<numChildren; i++) {
            cout << "Value for child " << i+1 << ": ";
            cin >> value;
            cout << endl;

            Node* new_child = new Node(value);
            curr->children.push_back(new_child);
            q.push(new_child);
        }
    }
}

void GenericTree::deleteTree() {
    delete this->root;
    this->root = NULL;
}


int GenericTree::size() {
    return size(this->root);
}

int GenericTree::size(Node* curr) {
    int count{0};

    for(auto x : curr->children) {
        count += size(x);
    }

    return count + 1;
}

int GenericTree::height() {
    return height(this->root);
}

int GenericTree::height(Node* curr) {
    if(curr == NULL) return 0;

    int max_height{0};

    for(auto x : curr->children) {
        max_height = max(max_height, height(x));
    }

    return max_height + 1;
}

int GenericTree::leafNodeCount() {
    return leafNodeCount(this->root);
}

int GenericTree::leafNodeCount(Node* curr) {
    if(curr->children.size() == 0) return 1;
    
    int count{0};
    for(auto x : curr->children) {
        count += leafNodeCount(x);
    }    

    return count;
}


void GenericTree::print() {
    if(this->root == NULL) return;

    queue<Node*> q;
    q.push(this->root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << ": ";

        for(auto x : curr->children) {
            cout << x->data << " ";
            q.push(x);
        }
        cout << endl;
    }
}

void GenericTree::printLevelOrder() {
    if(this->root == NULL) return;

    cout << "Level Order: ";
    printLevelOrder(this->root);
    cout << endl;
}

void GenericTree::printLevelOrder(Node* curr) {
    queue<Node*> q;

    q.push(curr);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        for(auto x : curr->children) {
            q.push(x);
        }
    }
}

void GenericTree::printPreTraversal() {
    if(this->root == NULL) return;

    cout << "Pre-traversal: ";
    printPreTraversal(this->root);
    cout << endl;
}

void GenericTree::printPreTraversal(Node* curr) {
    cout << curr->data << " ";

    for(auto x : curr->children) {
        printPreTraversal(x);
    }
}

void GenericTree::printPostTraversal() {
    if(this->root == NULL) return;

    cout << "Post-traversal: ";
    printPostTraversal(this->root);
    cout << endl;
}

void GenericTree::printPostTraversal(Node* curr) {
    for(auto x : curr->children) {
        printPostTraversal(x);
    }

    cout << curr->data << " ";
}

void GenericTree::printKLevel(int k) {
    if(this->root == NULL) return;

    cout << "K Level (" << k << "): ";
    printKLevel(this->root, k);
    cout << endl;
}

void GenericTree::printKLevel(Node* curr, int k) {
    if(k == 0) {
        cout << curr->data << " ";
        return;
    }

    for(auto x : curr->children) {
        printKLevel(x, k-1);
    }
}

// Test Case: 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0

int main() {
    GenericTree t;
    t.createTree();
    t.print();
    t.printLevelOrder();
    t.printPreTraversal();
    t.printPostTraversal();
    t.printKLevel(2);
    cout << "Tree size: " << t.size() << endl;
    cout << "Tree height: " << t.height() << endl;
    cout << "Leaf node count: " << t.leafNodeCount() << endl;
    return 0;
}
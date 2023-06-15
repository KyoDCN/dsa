#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~Node() {
        delete this->left;
        delete this->right;
    }
};

class BinaryTree {
    Node* root;

    Node* find(Node* curr, const int& key);

    int minValue(Node* curr);
    int maxValue(Node* curr);
    int size(Node* curr);
    int leafNodeCount(Node* curr);
    pair<int, int> maxDiameter(Node* curr);
    bool isSymmetric(Node* left, Node* right);

    void printPreTraversal(Node* curr);
    void printPostTraversal(Node* curr);
public:
    BinaryTree() {
        this->root = NULL;
    }

    ~BinaryTree() {
        if(this->root != NULL)
            delete this->root;
    }

    void createTree();
    void deleteTree();
    Node* find(const int& key);

    int size();
    bool isSymmetric();
    int minValue();
    int maxValue();
    int leafNodeCount();
    int maxDiameter();

    void print();
    void printLevelOrder();
    void printPreTraversal();
    void printPostTraversal();
};

void BinaryTree::createTree() {
    queue<Node*> q;

    int value;
    cout << "Node value: ";
    cin >> value;

    this->root = new Node(value);

    q.push(this->root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "[Node " << curr->data << "] L value: ";
        cin >> value;
        if(value != -1) {
            curr->left = new Node(value);
            q.push(curr->left);
        }

        cout << endl;

        cout << "[Node " << curr->data << "] R value: ";
        cin >> value;
        if(value != -1) {
            curr->right = new Node(value);
            q.push(curr->right);
        }

        cout << endl;
    }
}

void BinaryTree::deleteTree() {
    delete this->root;
    this->root = NULL;
}

Node* BinaryTree::find(const int& key) {
    if(this->root == NULL) return NULL;

    return find(this->root, key);
}

Node* BinaryTree::find(Node* curr, const int& key) {
    if(curr == NULL) return NULL;
    if(curr->data == key) return curr;

    Node* left = find(curr->left, key);
    Node* right = find(curr->right, key);

    return left != NULL ? left : right;
}


int BinaryTree::minValue() {
    return minValue(this->root);
}

int BinaryTree::minValue(Node* curr) {
    if(curr == NULL) return INT_MAX;

    return min(curr->data, min(minValue(curr->left), minValue(curr->right)));
}

int BinaryTree::maxValue() {
    return maxValue(this->root);
}

int BinaryTree::maxValue(Node* curr) {
    if(curr == NULL) return INT_MIN;

    return max(curr->data, max(maxValue(curr->left), maxValue(curr->right)));
}

int BinaryTree::size() {
    return size(this->root);
}

int BinaryTree::size(Node* curr) {
    if(curr == NULL) return 0;

    return size(curr->left) + size(curr->right) + 1;
}

int BinaryTree::leafNodeCount() {
    return leafNodeCount(this->root);
}

int BinaryTree::leafNodeCount(Node* curr) {
    if(curr->left == NULL && curr->right == NULL) return 1;

    return leafNodeCount(curr->left) + leafNodeCount(curr->right);
}

int BinaryTree::maxDiameter() {
    return maxDiameter(this->root).second;
}

pair<int, int> BinaryTree::maxDiameter(Node* curr) {
    if(curr == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> l_pair = maxDiameter(curr->left);
    pair<int, int> r_pair = maxDiameter(curr->left);

    int l_height = l_pair.first;
    int l_diameter = l_pair.second;

    int r_height = r_pair.first;
    int r_diameter = r_pair.second;

    pair<int, int> result;

    result.first = 1 + max(l_height, r_height);
    result.second = max(l_height+r_height, max(l_diameter, r_diameter));

    return result;
}

bool BinaryTree::isSymmetric() {
    return isSymmetric(this->root->left, this->root->right);
}

bool BinaryTree::isSymmetric(Node* left, Node* right) {
    if(left == NULL && right != NULL) return false;
    if(left != NULL && left == NULL) return false;
    if(left == NULL && right == NULL) return true;

    if(left->data != right->data) return false;

    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}


void BinaryTree::print() {
    queue<Node*> q;

    q.push(this->root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << ":";

        if(curr->left) {
            cout << " L" << curr->left->data;
            q.push(curr->left);
        }

        if(curr->right) {
            cout << " R" << curr->right->data;
            q.push(curr->right);
        }

        cout << endl;
    }
}

void BinaryTree::printLevelOrder() {
    if(this->root == NULL) return;

    cout << "Level Order Traversal: ";
    
    queue<Node*> q;
    q.push(this->root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }

    cout << endl;
}

void BinaryTree::printPreTraversal() {
    if(this->root == NULL) return;
    cout << "Pre-Traversal: ";
    printPreTraversal(this->root);
    cout << endl;
}

void BinaryTree::printPreTraversal(Node* curr) {
    if(curr == NULL) return;

    cout << curr->data << " ";

    printPreTraversal(curr->left);
    printPreTraversal(curr->right);
}

void BinaryTree::printPostTraversal() {
    if(this->root == NULL) return;
    cout << "Post-Traversal: ";
    printPostTraversal(this->root);
    cout << endl;
}

void BinaryTree::printPostTraversal(Node* curr) {
    if(curr == NULL) return;

    printPostTraversal(curr->left);
    printPostTraversal(curr->right);

    cout << curr->data << " ";
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 2 4 5 5 4 -1 -1 -1 -1 -1 -1 -1 -1

int main() {
    BinaryTree bt;
    bt.createTree();
    bt.print();
    bt.printLevelOrder();
    bt.printPreTraversal();
    bt.printPostTraversal();
    cout << "Is Symmetric? " << boolalpha << bt.isSymmetric() << endl;
    Node* n = bt.find(6);
    cout << (n != NULL ? to_string(n->data) : "Not Found") << endl;
    cout << "Tree Size: " << bt.size() << endl;
    cout << "Leaf Node Count: " << bt.leafNodeCount() << endl;
    cout << "Min Value: " << bt.minValue() << endl;
    cout << "Max Value: " << bt.maxValue() << endl;

    return 0;
}
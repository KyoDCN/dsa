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

class BinarySearchTree {
    Node* root;
    Node* insert(Node* curr, const int& key);
    Node* remove(Node* curr, const int& key);
    Node* search(Node* curr, const int& key);

    Node* buildBalancedBst(Node* curr, vector<int> a, int s, int e);
    pair<Node*, Node*> toLinkedList(Node* curr);

    bool isBst(Node* curr, int leftMinRange, int rightMaxRange);
    void rangeSum(Node* curr, const int& leftMinRange, const int& rightMaxRange, int& totalSum);
    int minValue(Node* curr);
    int maxValue(Node* curr);
public:
    int minValue();
    int maxValue();
    int rangeSum(const int& leftRange, const int& rightRange);
    bool isBst(int leftRange, int rightRange);

    void buildBalancedBst(vector<int> a);
    Node* toLinkedList();

    void insert(const int& key);
    void remove(const int& key);
    Node* search(const int& key);
};

void BinarySearchTree::insert(const int& key) {
    this->root = insert(this->root, key);
}

Node* BinarySearchTree::insert(Node* curr, const int& key) {
    if(curr == NULL) {
        curr = new Node(key);
        curr->left = NULL;
        curr->right = NULL;
        return curr;
    }

    if(key < curr->data) {
        curr->left = insert(curr->left, key);
    } else if (key > curr->data) {
        curr->right = insert(curr->right, key);
    }

    return curr;
}

void BinarySearchTree::remove(const int& key) {
    remove(this->root, key);
}

Node* BinarySearchTree::remove(Node* curr, const int& key) {
    if(curr == NULL) return NULL;

    if(key == curr->data) {
        if(curr->left == NULL && curr->right == NULL) {
            delete curr;
            return NULL;
        } else if (curr->right == NULL) {
            Node* n_left = curr->left;
            curr->left = NULL;
            delete curr;
            return n_left;
        } else if (curr->left == NULL) {
            Node* n_right = curr->right;
            curr->right = NULL;
            delete curr;
            return n_right;
        } else {
            Node* min_node = curr->right;
            while(min_node->left) {
                min_node = min_node->left;
            }
            curr->data = min_node->data;
            curr->right = remove(curr->right, curr->data);
            return curr;
        }
    }

    if(key < curr->data) {
        curr->left = remove(curr->left, key);
    } else if (key > curr->data) {
        curr->right = remove(curr->right, key);
    }
}

Node* BinarySearchTree::search(const int& key) {
    return search(this->root, key);
}

Node* BinarySearchTree::search(Node* curr, const int& key) {
    if(curr == NULL) return NULL;
    if(key == curr->data) return curr;

    if(key < curr->data) {
        return search(curr->left, key);
    } else if (key > curr->data) {
        return search(curr->right, key);
    }
}

bool BinarySearchTree::isBst(int leftRange, int rightRange) {
    return isBst(this->root, leftRange, rightRange);
}

bool BinarySearchTree::isBst(Node* curr, int leftMinRange, int rightMaxRange) {
    if(curr == NULL) return true;

    if(curr->data < leftMinRange) return false;
    if(curr->data > rightMaxRange) return false;

    return isBst(curr->left, leftMinRange, curr->data) && isBst(curr->right, curr->data, rightMaxRange);
}

int BinarySearchTree::minValue() {
    if(this->root == NULL) return 0;

    return minValue(this->root);
}

int BinarySearchTree::minValue(Node* curr) {
    while(curr->left) {
        curr = curr->left;
    }

    return curr->data;
}

int BinarySearchTree::maxValue() {
    if(this->root == NULL) return 0;

    return maxValue(this->root);
}

int BinarySearchTree::maxValue(Node* curr) {
    while(curr->right) {
        curr = curr->right;
    }

    return curr->data;
}

int BinarySearchTree::rangeSum(const int& leftRange, const int& rightRange) {
    int answer{0};
    rangeSum(this->root, leftRange, rightRange, answer);
    return answer;
}

void BinarySearchTree::rangeSum(Node* curr, const int& leftMinRange, const int& rightMaxRange, int& totalSum) {
    if(curr == NULL) return;
    
    if(curr->data >= leftMinRange && curr->data <= rightMaxRange) {
        totalSum += curr->data;
    }

    if(curr->data < leftMinRange) {
        rangeSum(curr->right, leftMinRange, rightMaxRange, totalSum);
    } else if (curr->data > rightMaxRange) {
        rangeSum(curr->left, leftMinRange, rightMaxRange, totalSum);
    } else {
        rangeSum(curr->left, leftMinRange, rightMaxRange, totalSum);
        rangeSum(curr->right, leftMinRange, rightMaxRange, totalSum);
    }
}

void BinarySearchTree::buildBalancedBst(vector<int> a) {
    this->root = buildBalancedBst(NULL, a, 0, a.size()-1);
}

Node* BinarySearchTree::buildBalancedBst(Node* curr, vector<int> a, int s, int e) {
    if(s > e) return NULL;

    int root_index = ((e-s)/2)+s;

    curr = new Node(a[root_index]);

    curr->left = buildBalancedBst(curr->left, a, s, root_index-1);
    curr->right = buildBalancedBst(curr->right, a, root_index+1, e);

    return curr;
}

Node* BinarySearchTree::toLinkedList() {
    pair<Node*, Node*> p = BinarySearchTree::toLinkedList(this->root);
    return p.first;
}

pair<Node*, Node*> BinarySearchTree::toLinkedList(Node* curr) {
    pair<Node*, Node*> p;

    if(curr->left == NULL && curr->right == NULL) {
        // create new node
        p.first = curr;
        p.second = curr;
    } else if (curr->left == NULL) {
        // Retrieve the tail
        p = toLinkedList(curr->right);
        
        // Attach curr as the new head node
        curr->right = p.first;
        p.first = curr;
    } else if (curr->right == NULL) {
        // Retrieve the head
        p = toLinkedList(curr->left);

        // Attach curr as the new tail node
        p.second->right = curr;
        curr->left = NULL; // Disconnect left node
        p.second = curr;
    } else {
        // the current node bridges the connection betwee two separate linked list
        // Left LL -> Current Node -> Right LL
        pair<Node*, Node*> p_left = toLinkedList(curr->left);
        pair<Node*, Node*> p_right = toLinkedList(curr->right);

        p.first = p_left.first;
        p_left.second->right = curr;
        curr->left = NULL; // Disconnect left node
        curr->right = p_right.first;
        p.second = p_right.second;
    }

    return p;
}

int main() {
    vector<int> a{1,2,3,4,5,6,7};

    BinarySearchTree bst;
    bst.buildBalancedBst(a);
    Node* head = bst.toLinkedList();

    while(head) {
        cout << head->data << " ";
        head = head->right;
    }

    return 0;
}
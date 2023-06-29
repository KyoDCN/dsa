#include<iostream>

using namespace std;

class Node {
public:
    bool isTerminal;
    Node* children[26];

    Node() {
        isTerminal = false;

        for(Node*& child : children) {
            child = NULL;
        }
    }

    ~Node() {
        for(Node* child : children) {
            delete child;
        }
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void add(string s);
    bool search(string s);
};

void Trie::add(string s) {
    Node* current = this->root;

    for(char c : s) {
        int c_index = toupper(c) - 'A';

        if(current->children[c_index] == NULL) {
            current->children[c_index] = new Node();
        }

        current = current->children[c_index];
    }

    current->isTerminal = true;
}

bool Trie::search(string s) {
    Node* current = this->root;

    for(char c : s) {
        int c_index = toupper(c) - 'A';

        if(current->children[c_index] == NULL) {
            return false;
        }

        current = current->children[c_index];
    }

    return current->isTerminal;
}

int main() {
    Trie t;
    t.add("Bacon");
    t.add("Is");
    t.add("Delicious");
    t.add("There");
    t.add("Is");
    t.add("No");
    t.add("Spoon");
    t.add("Chicken");

    cout << boolalpha << t.search("baconx") << endl;
    cout << boolalpha << t.search("Delicious") << endl;

    return 0;
}
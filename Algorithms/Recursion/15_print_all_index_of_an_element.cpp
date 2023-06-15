#include<iostream>
#include<vector>

using namespace std;

void print_index(int& key, int i, vector<int>& a) {
    if(i == a.size()) return;

    if(key == a[i]) {
        cout << i << " ";
    }

    print_index(key, i+1, a);
}

int main() {
    vector<int> a{1,5,2,5,3,5,4,5,5,6,5,7,5,8,5,9};
    int key = 5;

    cout << "Indexes of key " << key << " are "; 
    print_index(key, 0, a); 

    return 0;
}
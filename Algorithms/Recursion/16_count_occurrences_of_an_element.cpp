#include<iostream>
#include<vector>

using namespace std;

int count_elements(int& key, int i, vector<int>& a) {
    if(i == a.size()) return 0;

    return (key == a[i] ? 1 : 0) + count_elements(key, i+1, a);
}

int main() {
    vector<int> a{1,5,2,5,3,5,4,5,5,6,5,7,5,8,5,9};
    int key = 5;

    cout << "key " << key << " occurs " << count_elements(key, 0, a) << " times."; 

    return 0;
}
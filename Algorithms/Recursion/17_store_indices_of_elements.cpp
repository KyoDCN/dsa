#include<iostream>
#include<vector>

using namespace std;

void retrieve_indexes_of_element(int& key, int i, vector<int>& a, vector<int>& result) {
    if(i == a.size()) return;

    if(key == a[i]) {
        result.push_back(i);
    }

    retrieve_indexes_of_element(key, i+1, a, result);
}

int main() {
    vector<int> a{1,5,2,5,3,5,4,5,5,6,5,7,5,8,5,9};
    int key = 5;
    
    vector<int> result;
    retrieve_indexes_of_element(key, 0, a, result);

    for(auto x : result) {
        cout << x << " ";
    }

    return 0;
}
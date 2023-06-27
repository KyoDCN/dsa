#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> smallest_k_values(vector<int> a, int k) {
    priority_queue<int> pq;

    for(int i=0; i<a.size(); i++) {
        pq.push(a[i]);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> result;

    while(!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

vector<int> largest_k_values(vector<int> a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<a.size(); i++) {
        pq.push(a[i]);
        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> result;
    while(!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

int main() {
    vector<int> a{12,56,34,98,44,21,68,74};
    vector<int> result = smallest_k_values(a, 3);
    vector<int> result2 = largest_k_values(a, 3);
    for(int i=0; i<3; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    for(int i=0; i<3; i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    // priority_queue<int> pq;
    // for(auto x : a) {
    //     pq.push(x);
    // }
    // for(int i=0; i<3; i++) {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void ksort(vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<k; i++) {
        pq.push(a[i]);
    }

    int lagging_index = 0;
    int leading_index = k;

    while(leading_index<a.size()) {
        a[lagging_index] = pq.top();
        pq.pop();
        pq.push(a[leading_index]);
        lagging_index++;
        leading_index++;
    }

    while(!pq.empty()) {
        a[lagging_index++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> a{10,12,6,7,9};
    ksort(a, 3);
    
    for(auto x : a) {
        cout << x << " ";
    }
    return 0;
}
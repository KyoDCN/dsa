#include<iostream>
#include<vector>

using namespace std;

void selection_sort(vector<int>& a) {
    for(int i=0; i<a.size(); i++) {
        int smaller_index{i};

        for(int j=i+1; j<a.size(); j++) {
            if(a[j] < a[smaller_index]) {
                smaller_index = j;
            }
        }

        swap(a[i], a[smaller_index]);
    }
}

int main() {
    vector<int> a{5,1,9,2,8,3,7,4,6};

    selection_sort(a);

    for(auto x : a) {
        cout << x << " ";
    }

    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int>& a) {
    for(int i=0; i<a.size(); i++) {
        bool already_sorted{true}; // Break out of loop if nothing left to sort

        for(int j=0; j<a.size()-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                already_sorted = false;
            }
        }

        if(already_sorted) break;
    }
}

void bubble_sort2(vector<int>& a) {
    bool sorted{false};
    
    while(sorted == false) {
        sorted = true;
        for(int j=0; j<a.size()-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                sorted = false;
            }
        }
    }
}

int main() {
    vector<int> a{5,1,9,2,8,3,7,4,6};

    bubble_sort2(a);

    for(auto x : a) {
        cout << x << " ";
    }

    return 0;
}
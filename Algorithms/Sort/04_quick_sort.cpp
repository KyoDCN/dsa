#include<iostream>
#include<vector>

using namespace std;

void quick_sort(vector<int>& a, int s, int e) {
    if(s >= e) return;

    int pivot{e};

    int s_indexer = s;
    int e_indexer = e;

    while(s_indexer < e_indexer) {
        // a[s] > a[p] seems to make it desc order
        while(a[s_indexer] < a[pivot]) {
            s_indexer++;
        } 

        while(a[e_indexer] > a[pivot]) {
            e_indexer--;
        }

        swap(a[s_indexer], a[e_indexer]);
    }

    // e_indexer is now the new pivot index
    // Technically, you can use s_indexer as the new pivot too.
    swap(a[e_indexer], a[pivot]);
    pivot = e_indexer;

    quick_sort(a, s, pivot-1);
    quick_sort(a, pivot+1, e);
}

int main() {
    vector<int> a{9,1,8,2,7,3,6,4,5};
    quick_sort(a, 0, a.size()-1);

    for(auto x : a) {
        cout << x << " ";
    }

    return 0;
}
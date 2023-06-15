#include<iostream>
#include<vector>

using namespace std;

vector<int> merge_sort(vector<int> a) {
    if(a.size() == 1) return a;

    vector<int> l;
    vector<int> r;

    int m = a.size()/2;

    for(int i=0; i<m; i++) {
        l.push_back(a[i]);
    }
    for(int i=m; i<a.size(); i++) {
        r.push_back(a[i]);
    }

    vector<int> l_result = merge_sort(l);
    vector<int> r_result = merge_sort(r);

    vector<int> result;
    int l_counter{0};
    int r_counter{0};
    
    while(l_counter < l_result.size() && r_counter < r_result.size()) {
        if(l_result[l_counter] < r_result[r_counter]) {
            result.push_back(l_result[l_counter]);
            l_counter++;
        } else {
            result.push_back(r_result[r_counter]);
            r_counter++;
        }
    }

    while(l_counter != l_result.size()) {
        result.push_back(l_result[l_counter]);
        l_counter++;
    }
    
    while(r_counter != r_result.size()) {
        result.push_back(r_result[r_counter]);
        r_counter++;
    }
    
    return result;
}

void merge_sort(int a[], int s, int e) {
    if(s == e) return;

    int m = ((e-s)/2)+s;

    merge_sort(a, s, m);
    merge_sort(a, m+1, e);

    for(int i=s; i<e; i++) {
        for(int j=i+1; j<e; j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


int main() {
    vector<int> a{9,1,8,2,7,3,6,4,5};
    vector<int> result = merge_sort(a);

    for(auto x : result) {
        cout << x << " ";
    }

    cout << endl;


    int a2[]{9,1,8,2,7,3,6,4,5};
    merge_sort(a2,0,9);
    
    for(auto x : a2) {
        cout << x << " ";
    }

    return 0;
}
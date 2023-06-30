#include<iostream>

using namespace std;

// Check if the k characters of the current result 
// all match the comparison character (c_cmp)
bool can_delete(char c_cmp, string result, int i, int k) {
    while(k > 0) {
        if(tolower(result[i]) != tolower(c_cmp)) {
            return false;
        }
        k--;
        i--;
    }

    return true;
}

string remove_adj_dup_k(string a, int k) {
    string result(a.size(), ' ');
    int result_indexer{-1}; // Start at -1, so we can push the first character at 0;
    k = k-1; // Decrement 1, so the indexer points correctly

    for(auto c : a) {
        // Only perform check if indexer is >= K, otherwise, we can't check K length
        if(result_indexer >= k && can_delete(c, result, result_indexer, k)) {
            result_indexer -= k;
        } else {
            result_indexer++;
            result[result_indexer] = c;
        }
    }

    return result.substr(0, result_indexer+1);
}

int main() {
    cout << remove_adj_dup_k("Miiiissiiiissiippppii", 3);
    return 0;
}
#include<iostream>

using namespace std;

/*
    Check if its possible to simply delete any one character
    to make it a valid palindrome
*/

bool isPalindrome(string a, size_t i_to_skip) {
    size_t s_itr{0};
    size_t e_itr{a.size()-1};

    while(s_itr < e_itr) {
        if(!isalnum(a[s_itr]) || s_itr == i_to_skip) {
            s_itr++;
            continue;
        }

        if(!isalnum(a[e_itr]) || e_itr == i_to_skip) {
            e_itr--;
            continue;
        }

        if(a[s_itr] != a[e_itr]) return false;

        s_itr++;
        e_itr--;
    }

    return true;
}
bool isPalindrome(string s) {
    if(isPalindrome(s, s.size())) {
        return true;
    }

    for(size_t i=0; i<s.size(); i++) {
        // Skip if not alphanum
        if(!isalnum(s[i])) continue;

        // Check if deleted char forms a palindrome
        if(isPalindrome(s, i)) {
            cout << "Delete " << s[i] << " at index " << i << endl;
            return true;
        };
    }

    return false;
}

// A more Big O time efficient way of doing it
bool isPalindrome_v2(string a) {
    size_t s{0};
    size_t e{a.size()-1};

    while(s < e) {
        if(!isalnum(a[s])) {
            s++;
            continue;
        }

        if(!isalnum(a[e])) {
            e--;
            continue;
        }

        if(a[s] != a[e]) {
            // This way, we don't have to excessively perform for loops O(N^2)
            // We can simply check in one loop if a character deletion is possible O(N)
            if(a[s+1] == a[e]) {
                s++; // Delete start_indexer character
            } else if (a[s] == a[e-1]) {
                e--; // Delete end_indexer character
            } else {
                return false; // Implies that no single deletion is possible to achieve valid palindrome
            }
        }

        s++;
        e--;
    }

    return true;
}

int main() {
    cout << isPalindrome_v2("abba x abcba");
    return 0;
}
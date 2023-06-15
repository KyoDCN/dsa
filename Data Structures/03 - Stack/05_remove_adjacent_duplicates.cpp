#include<iostream>
#include<stack>

using namespace std;

string input{"Mississippi"};

string remove_adj_duplicates(string a) {
    stack<char> s;

    for(auto x : a) {
        if(!s.empty() && s.top() == x) {
            s.pop();
        } else {
            s.push(x);
        }
    }

    string result;
    while(!s.empty()) {
        result = s.top() + result;
        s.pop();
    }

    return result;
}

int main() {
    cout << remove_adj_duplicates(input);
    return 0;
}
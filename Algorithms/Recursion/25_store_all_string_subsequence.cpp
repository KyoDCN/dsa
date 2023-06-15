#include<iostream>
#include<vector>

using namespace std;

void generate_subsequence(string input, string output, vector<string>& subsequences) {
    if(input.empty()) {
        subsequences.push_back(output);
        return;
    }

    generate_subsequence(input.substr(1), output + input[0], subsequences);
    generate_subsequence(input.substr(1), output, subsequences);
}

int main() {
    string input{"abc"};
    string output;
    vector<string> subsequences;

    generate_subsequence(input, output, subsequences);

    for(auto x : subsequences) {
        cout << x << endl;
    }

    return 0;
}
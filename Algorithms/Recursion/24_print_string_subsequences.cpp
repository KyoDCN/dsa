#include<iostream>

using namespace std;

void print_subsequence(string input, string output) {
    if(input.empty()) {
        cout << output << endl;
        return;
    }

    print_subsequence(input.substr(1), output + input[0]);
    print_subsequence(input.substr(1), output);
}

void print_subsequence(char input[], char output[], int i) {
    if(input[0] == '\0') {
        output[i] = '\0';
        cout << output << endl;
        return;
    }

    output[i] = input[0];

    print_subsequence(input+1, output, i+1);
    print_subsequence(input+1, output, i);
}

int main() {
    // char a[]{"abc"};
    // char o[3];
    // print_subsequence(a, o, 0);

    string input{"abc"};
    string output;
    
    print_subsequence(input, output);
    
    return 0;
}
#include<iostream>

using namespace std;

int length(char word[]) {
    int count{0};

    for(int i=0; word[i] != '\0'; i++) {
        count++;
    }
    
    return count;
}

int main() {
    char word[] = "Bacon";

    cout << length(word);
}
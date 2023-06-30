#include<iostream>

using namespace std;

bool isPalindrome(string phrase) {
    size_t start_itr{0};
    size_t end_itr{phrase.size()-1};

    while(start_itr < end_itr) {
        // If char not alphanum, increment
        if(!isalnum(phrase[start_itr])) {
            start_itr++;
            continue;
        } 

        // If char not alphanum, decrement
        if(!isalnum(phrase[end_itr])) {
            end_itr--;
            continue;
        }

        if(tolower(phrase[start_itr]) != tolower(phrase[end_itr])) {
            return false;
        }

        start_itr++;
        end_itr--;
    }

    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
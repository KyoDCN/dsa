#include<iostream>
#include<string.h>

using namespace std;

int main() {
    int len = strlen("Bacon");
    cout << "Length: " << len << endl;
    
    int cmp = strcmp("Bacon", "Not Bacon"); // 0 true / -1 false
    cout << "Compare: " << cmp << endl;
    
    char dest1[]{"Good Bye"};
    char src1[]{"Hello"};
    strcpy(dest1, src1); // Completely overrides destination
    cout << "Copy: " << dest1 << endl;
    
    char dest2[]{"Good Bye"};
    char src2[]{"Hello"};
    strncpy(dest2, src2, 3); // Overrides only N amount of the destination
    cout << "Copy N: " << dest2 << endl;

    char dest3[]{"Good Bye"};
    char src3[]{"Hello"};
    strcat(dest3, src3); // Combines src with destination -> dest + src
    cout << "Concat: " << dest3 << endl;

}
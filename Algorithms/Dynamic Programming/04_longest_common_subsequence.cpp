#include<iostream>

using namespace std;

int longest_common_subsequence(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 | j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1{"maple"};
    string s2{"apple"};

    cout << longest_common_subsequence(s1,s2);

    return 0;
}
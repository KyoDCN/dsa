#include<iostream>

using namespace std;

int min_dist_word(string s1, int s1_index, string s2, int s2_index) {
    if(s1_index == 0) return s2_index; //Insert rest of characters
    if(s2_index == 0) return s1_index; //Delete rest of characters

    if(s1[s1_index-1] == s2[s2_index-1]) {
        return min_dist_word(s1, s1_index-1, s2, s2_index-1);
    } else {
        int insert = min_dist_word(s1, s1_index, s2, s2_index-1);
        int remove = min_dist_word(s1, s1_index-1, s2, s2_index);
        int replace = min_dist_word(s1, s1_index-1, s2, s2_index-1);

        return min(insert, min(remove, replace)) + 1;
    }
}

int min_dist_word_v2(string s1, int s1_index, string s2, int s2_index) {
    if(s1_index == s1.size()) return s2.size() - s2_index; //Insert rest of characters
    if(s2_index == s2.size()) return s1.size() - s1_index; //Delete rest of characters

    if(s1[s1_index] == s2[s2_index]) {
        return min_dist_word_v2(s1, s1_index+1, s2, s2_index+1);
    } else {
        int insert = min_dist_word_v2(s1, s1_index+1, s2, s2_index);
        int remove = min_dist_word_v2(s1, s1_index, s2, s2_index+1);
        int replace = min_dist_word_v2(s1, s1_index+1, s2, s2_index+1);

        return min(insert, min(remove, replace)) + 1;
    }
}

int min_dist_word_dp(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            // i=0 implies only insertion is being performed, with the number of insertion = j
            if(i == 0) {
                dp[i][j] = j;
                continue;
            }

            // j=0 implies only deletion is being performed, with the number of deletion = i
            if(j == 0) {
                dp[i][j] = i;
                continue;
            }

            // If previous characters match, simply retrieve previous value;
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int insert = dp[i][j-1];
                int remove = dp[i-1][j];
                int replace = dp[i-1][j-1];

                // +1 to increment step taken
                dp[i][j] = min(insert, min(remove, replace)) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "chicken";
    string s2 = "bacon";
    cout << min_dist_word(s1, s1.size(), s2, s2.size()) << endl;
    cout << min_dist_word_v2(s1, 0, s2, 0) << endl;
    cout << min_dist_word_dp(s1, s2) << endl;

    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int knapsack(int n, int remaining_weight, vector<int> item_weights, vector<int> item_prices) {
    if(n == 0 || remaining_weight == 0) return 0;

    if(item_weights[n-1] > remaining_weight) {
        return knapsack(n-1, remaining_weight, item_weights, item_prices);
    } else {
        int included = item_prices[n-1] + knapsack(n-1, remaining_weight - item_weights[n-1], item_weights, item_prices);
        int excluded = knapsack(n-1, remaining_weight, item_weights, item_prices);

        return max(included, excluded);
    }
}

int knapsack_dp(int max_weight, vector<int> item_weights, vector<int> item_prices) {
    int num_items = item_prices.size();

    int dp[max_weight+1]{0};

    for(int item=0; item<num_items; item++) {
        for(int weight=max_weight; weight>=0; weight--) {
            if(item_weights[item] <= weight) {
                int included = item_prices[item] + dp[weight - item_weights[item]];
                int excluded = dp[weight];

                dp[weight] = max(included, excluded);
            }
        }
    }

    return dp[max_weight];
}

int knapsack_dp_v2(int max_weight, vector<int> item_weights, vector<int> item_prices) {
    int n = item_weights.size();
    int m = max_weight;

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            // Zero item or zero weight implies zero price
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            // if current item's weight exceeds the current remaining weight,
            // current total price = previous total price.
            // In other words, we do nothing
            if(item_weights[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                // Determine the maximum between including and excluding the current item
                int included = item_prices[i-1] + dp[i-1][j - item_weights[i-1]];
                int excluded = dp[i-1][j];

                dp[i][j] = max(included, excluded);
            }
        }
    }

    return dp[n][m];
}

int main() {
    vector<int> a{60,100,120};
    vector<int> b{10,20,30};

    //cout << knapsack(a.size(), 50, a, b);
    cout << knapsack(3, 50, b, a) << endl;
    cout << knapsack_dp_v2(50, b, a) << endl;

    return 0;
}
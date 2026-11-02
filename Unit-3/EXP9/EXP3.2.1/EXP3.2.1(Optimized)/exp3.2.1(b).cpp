#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);    //creates the DP table, a vector with amount + 1
    dp[0] = 0;   //base case
    for (int a = 1; a <= amount; a++) {   //fills the table from left to right
        for (int c : coins) {   //tries every coin type as the last coin handed over to reach amount a
            if (c <= a) {
                dp[a] = min(dp[a], dp[a - c] + 1);    //whole algorithm
            }
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];   //if the cell still holds the sentinel, so the target is impossible, return -1
}
int main(){
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter amount: ";
    cin >> amount;
    int result = coinChange(coins, amount);
    cout << "Output: " << result << endl;
    return 0;
}

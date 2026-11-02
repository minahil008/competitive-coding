#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;    //creates a constant of infinity
int solve(int t, vector<int>& coins) {
    if (t == 0) {   //base case (target 0)
        return 0;
    }
    int best = INF;  //variable tracking the fewest coins found so far
    for (int c : coins) {    //for each coin c in coins
        if (c <= t) {    //only consider coins that fit
            best = min(best, solve(t - c, coins) + 1);  //whole algorithm
        }
    }
    return best;
}
int coinChange(vector<int>& coins, int amount) {
    int ans = solve(amount, coins);    //starts the recursion with the full amount
    return (ans < INF) ? ans : -1;     //ternary operator (if ans is less than INF, return ans)
}
int main() {
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;
int minCost(vector<int>& height, int k) {
    int n = height.size();
    vector<int> dp(n, 0);    //DP table
    for (int i = 1; i < n; i++){    //fills the table one stone at a time from left to right
        int best = INT_MAX;
        for (int j = max(0, i - k); j < i; j++){  //every stone j that could have jumped to stone i
            int cost = dp[j] + abs(height[i] - height[j]);   //total cost of one candidate route
            best = min(best, cost);
        }
        dp[i] = best;
    }
    return dp[n - 1];
}
int main() {
    int n, k;
    cout << "Enter number of stones: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << "Enter k: ";
    cin >> k;
    int result = minCost(height, k);
    cout << "Output: " << result << endl;
    return 0;
}

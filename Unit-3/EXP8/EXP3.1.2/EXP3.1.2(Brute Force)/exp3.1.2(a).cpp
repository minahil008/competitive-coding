#include <iostream>
#include <vector>
#include <algorithm>  //gives min(), max() functions
#include <climits>
#include <cstdlib>   //gives func like abs()
using namespace std;
int solve(int i, vector<int>& height, int k) {
    if (i == 0){  //base case
        return 0;
    }
    int best = INT_MAX;   //holds the cheapest cost found so far
    for (int j = max(0, i - k); j < i; j++) {    //if i-k is -ve
        best = min(best, solve(j, height, k) + abs(height[i] - height[j]));   //formula to calculate cheapest arrival cost
    }
    return best;
}
int minCost(vector<int>& height, int k) {
    int n = height.size();    //how many elements are in the vector
    return solve(n - 1, height, k);  //cheapest cost to reach the last stone
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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int lcs(string text1, string text2){
//returns how many characters a string has:
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));   //2D table
    for (int i = 1; i <= m; i++) {    //walks down the rows
        for (int j = 1; j <= n; j++) {    //walks across the columns of the current row
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  //the characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);    //the characters differ
            }
        }
    }
    return dp[m][n];
}
int main() {
    string text1, text2;
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;
    int result = lcs(text1, text2);
    cout << "Output: " << result << endl;
    return 0;
}

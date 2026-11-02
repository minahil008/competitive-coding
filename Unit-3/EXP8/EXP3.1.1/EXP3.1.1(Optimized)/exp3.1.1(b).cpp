#include <iostream>
using namespace std;
int climbStairs(int n) {
    if (n <= 2) {  //base case
        return n;
    }
//holding the two most recent answers:
    int prev1 = 1;     //the answer two steps back
    int prev2 = 2;   //the answer one step back
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;    //formula ways(i-1) + ways(i-2) written in code
    //slide the window forward:
        prev1 = prev2;   //two steps back
        prev2 = current;   //one step back
    }
    return prev2;
}
int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    int result = climbStairs(n);
    cout << "Output: " << result << endl;
    return 0;
}

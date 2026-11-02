#include <iostream>
using namespace std;
int climb(int n) {
    if (n <= 2) {   //base case
        return n;
    }
    return climb(n - 1) + climb(n - 2);    //direct formula using recursion
}
int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    int result = climb(n);
    cout << "Output: " << result << endl;
    return 0;
}

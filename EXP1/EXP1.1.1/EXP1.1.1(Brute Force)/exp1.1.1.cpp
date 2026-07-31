#include <iostream>
#include <vector>
#include <cmath>   // for math functions (here abs (i - j))
using namespace std;
bool NearbyDuplicate(vector<int>& nums, int k) { // & manipulates the original array instead of making a copy, k is the max allowed dist. between the duplicated
    int n = nums.size();  // stores total no. of elements
    for (int i = 0; i < n; i++) { // outer loop for anchor element
        for (int j = i + 1; j < n; j++) {  // inner loop for the comparison (starts from i+1 so we don't compare the no. with itself)
            if (nums[i] == nums[j] && abs(i - j) <= k) {  // i==j for duplicate, i-j<=k for allowed dist., and abs is used so the o/p is +ve (||)
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter value of k: ";
    cin >> k;
    bool result = NearbyDuplicate(nums, k);
    cout << "Output: " << (result ? "true" : "false") << endl;  // used the ternary operator "?" bcz bool gives t/f in 0/1 so to change it to t/f
    return 0;
}

#include <iostream>
#include <vector>   // resizable array
#include <cmath>   // for math functions (here abs (i - j))
using namespace std;
bool NearbyDuplicate(vector<int>& nums, int k) { //
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j] && abs(i - j) <= k) {
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
    cout << "Output: " << (result ? "true" : "false") << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {  // just brute force checking ignoring any structure of array
            return i;
        }
    }
    return -1;  // if target isn't found
}
int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements (possibly rotated): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    cin >> target;
    int result = search(nums, target);
    cout << "Output: " << result << endl;
    return 0;
}

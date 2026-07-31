#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;  // to avoid overflow
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[left] <= nums[mid]) {  // Case I: to check if left half is sorted
            if (nums[left] <= target && target < nums[mid]) {   // if target value fits between this
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        else {
            if (nums[mid] < target && target <= nums[right]) {   // Case II: right half must be sorted
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
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

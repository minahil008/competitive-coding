#include <iostream>
#include <vector>
using namespace std;
int Search(vector<int>& nums, int target) {  // target=>the no. we're searching for
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {  //if current no. = target
            return i;
        }
        if (nums[i] > target) {  //if target isn't here, insert it in sorted manner
            return i;
        }
    }
    return n;
}
int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    cin >> target;
    int result = Search(nums, target);
    cout << "Output: " << result << endl;
    return 0;
}

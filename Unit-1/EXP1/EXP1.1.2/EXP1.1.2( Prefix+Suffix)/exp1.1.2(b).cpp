#include <iostream>
#include <vector>
using namespace std;
vector<int> Product(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);
    for (int i = 1; i < n; i++) { // start from 1 (0 will make everything 0 for multiplication)
        answer[i] = answer[i - 1] * nums[i - 1];  // (answer that already was)*(number before i)
    } // for prefix
    int right = 1;  // now for suffix start from 1
    for (int i = n - 1; i >= 0; i--) {  // backward loop for right side
        answer[i] *= right;  // (answer from prefix)*(suffix)
        right *= nums[i]; // multiply right by current no.
    }

    return answer;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = Product(nums);
    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

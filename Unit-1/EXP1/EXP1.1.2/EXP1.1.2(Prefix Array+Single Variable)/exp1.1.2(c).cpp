#include <iostream>
#include <vector>
using namespace std;
vector<int> producT(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, 1);  // separate array for prefix
    vector<int> answer(n, 1);
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] = prefix[i] * right;
        right *= nums[i];
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
    vector<int> result = producT(nums);
    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

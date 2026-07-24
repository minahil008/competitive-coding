#include <iostream>
#include <vector>
using namespace std;
vector<int> product(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);  // new vector called answer with size n with every element initialized to 1 (not 0 cuz of multiplication)
    for (int i = 0; i < n; i++) {
        int product = 1;  // fresh local variable reset to 1, restarts for every new index
        for (int j = 0; j < n; j++) {
            if (j != i) {  // if j==i => skip
                product *= nums[j];
            }
        }
        answer[i] = product;
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
    vector<int> result = product(nums);
    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

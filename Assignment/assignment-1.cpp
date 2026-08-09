#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int k = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = sol.removeDuplicates(nums1);
    cout << "k = " << k1 << ", array = ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << endl;
    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k2 = sol.removeDuplicates(nums2);
    cout << "k = " << k2 << ", array = ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << endl;
    return 0;
}

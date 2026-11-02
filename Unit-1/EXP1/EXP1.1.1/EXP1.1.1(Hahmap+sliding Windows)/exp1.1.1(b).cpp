#include <iostream>
#include <vector>
#include <unordered_map>  // for hashmap data structure
using namespace std;
bool nearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> seen;  // hashmap (key:value pairs) named seen
    int n = nums.size();
    for (int i = 0; i < n; i++) {  // a single loop (we go through the array ONCE)
        if (seen.find(nums[i]) != seen.end() && (i - seen[nums[i]]) <= k) {  // seen.find searches hashmap for curent no., .end if no. not found (so! means it was duplicated (found)), seen[nums[i]] for the no. compared to
            return true;
        }
        seen[nums[i]] = i;  // runs iff no. wasn't found to overwrite with new no. (for the one compared to) (only the latest one)
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
    bool result = nearbyDuplicate(nums, k);
    cout << "Output: " << (result ? "true" : "false") << endl;
    return 0;
}

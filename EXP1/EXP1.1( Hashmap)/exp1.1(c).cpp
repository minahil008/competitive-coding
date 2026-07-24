#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool NearByDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> indexMap; // here vector saves all indices not just the recent ones
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        indexMap[nums[i]].push_back(i);  // indexMap accesses the indices, pushback adds current i to vector
    }
    for (auto& pair : indexMap) {  // loops through every entry (pair is just the key-value pairs)
        vector<int>& indices = pair.second; // pair.second is the VALUE of index
        for (int i = 0; i < indices.size(); i++) {  // brute force approach to check every pair
            for (int j = i + 1; j < indices.size(); j++) {
                if (abs(indices[i] - indices[j]) <= k) {
                    return true;
                }
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
    bool result = NearByDuplicate(nums, k);
    cout << "Output: " << (result ? "true" : "false") << endl;
    return 0;
}

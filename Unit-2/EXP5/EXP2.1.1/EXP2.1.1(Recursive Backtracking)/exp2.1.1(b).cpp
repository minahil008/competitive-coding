#include <iostream>
#include <vector>
using namespace std;
void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){  //passed by reference
    result.push_back(current);   //immediately at start we copy this to result even if its empty
    for (int i = start; i < nums.size(); i++){  //starts at "start" so we pick where we left off
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);  //explore every possible way to extend this subset further
        current.pop_back();   //pop nums[i] (backtrack) so we start fresh again with new element
    }
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = subsets(nums);
    cout << "Output:\n";
    for (auto& subset : result){
        cout << "[ ";
        for (int val : subset){
            cout << val << " ";
        }
        cout << "]\n";
    }
    return 0;
}

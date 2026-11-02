#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums){  //vector of vectors used here as we need list of lists (i.e., every list is a subset itself)
    int n = nums.size();  //stores how many elements are in num
    vector<vector<int>> result;  //we'll collect every subset we generate here
    int totalSubsets = 1 << n;   //calculates 2^n using left bit shift operator
    for (int mask = 0; mask < totalSubsets; mask++){
        vector<int> subset;
        for (int i = 0; i < n; i++){   //check every position i to decide whether to include nums[i]
            if (mask & (1 << i)) {    //1<<i => creates a no. that has only ith bit on, eg., 010 has 1 on and 001 has 0 on
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
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

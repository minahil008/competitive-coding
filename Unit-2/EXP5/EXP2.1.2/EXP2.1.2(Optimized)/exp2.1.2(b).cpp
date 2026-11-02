#include <iostream>
#include <vector>
using namespace std;
void backtrack(vector<int>& candidates, int start, int remaining, vector<int>& current, vector<vector<int>>& result){  //start->the index we should start considering candidates from(prevents preordered duplicates)
    if (remaining == 0){
        result.push_back(current);  //save copy of current directly in result
        return;
    }
    for (int i = start; i < candidates.size(); i++){   //doesn't check every candidate from beginning, loops from start onwards (prevents duplicates)
        if (candidates[i] <= remaining){   //pruning check (saving wasted recursive calls)
            current.push_back(candidates[i]);
            backtrack(candidates, i, remaining - candidates[i], current, result);  //recurse deeper
            current.pop_back();  //backtrack
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, 0, target, current, result);
    return result;
}
int main(){
    int n, target;
    cout << "Enter number of candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    cout << "Enter target: ";
    cin >> target;
    vector<vector<int>> result = combinationSum(candidates, target);
    cout << "Output:\n";
    for (auto& combo : result) {
        cout << "[ ";
        for (int val : combo) {
            cout << val << " ";
        }
        cout << "]\n";
    }
    return 0;
}

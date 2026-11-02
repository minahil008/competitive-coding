#include <iostream>
#include <vector>
#include <algorithm>    //gives sort()
#include <set>          // set is a container that automatically removes duplicates
using namespace std;
/*vector<int>& candidates(list of no. we're allowed to pick from
remaining(how much more is to be added to reach target
vector<int>& current(combination currently building
set<vector<int>>& resultSet(container that holds complete valid combinations (set in cpp holds any type)*/
void solve(vector<int>& candidates, int remaining, vector<int>& current, set<vector<int>>& resultSet){
    if (remaining == 0){   //if remaining = 0 => target reached
        vector<int> sortedCombo = current;   //makes copy of current
        sort(sortedCombo.begin(), sortedCombo.end());  //sorts the copy in ascending order
        resultSet.insert(sortedCombo);
        return;
    }
    if (remaining < 0){   //if remaining is -ve it means combination has gone beyond target, drop immediately
        return;
    }
    for (int c : candidates){  //checking all combinations
        current.push_back(c);   //tentatively adds candidate to combination
        solve(candidates, remaining - c, current, resultSet);  //recurse deeper
        current.pop_back();   //backtrack so next iteration tries diff candidate
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    set<vector<int>> resultSet;
    vector<int> current;
    solve(candidates, target, current, resultSet);
    vector<vector<int>> result(resultSet.begin(), resultSet.end());
    return result;
}
int main(){
    int n, target;
    cout << "Enter number of candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++){
        cin >> candidates[i];
    }
    cout << "Enter target: ";
    cin >> target;
    vector<vector<int>> result = combinationSum(candidates, target);
    cout << "Output:\n";
    for (auto& combo : result){
        cout << "[ ";
        for (int val : combo){
            cout << val << " ";
        }
        cout << "]\n";
    }
    return 0;
}

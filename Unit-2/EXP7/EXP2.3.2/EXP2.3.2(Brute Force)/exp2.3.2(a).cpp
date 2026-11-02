#include <iostream>
#include <vector>
#include <unordered_set>   //unsorted container storing unique values only
using namespace std;
int findDuplicate(vector<int>& nums){
    unordered_set<int> seen;  //Creates an empty set
    for (int x : nums){   //read each integer x "in" nums
        if (seen.find(x) != seen.end()){   //searches if num is already seen before
            return x;
        }
        seen.insert(x);  //if not, add in seen
    }
    return -1;
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
    int result = findDuplicate(nums);
    cout << "Output: " << result << endl;
    return 0;
}

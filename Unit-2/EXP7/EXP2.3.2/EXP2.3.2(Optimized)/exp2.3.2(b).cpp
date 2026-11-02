#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    do{
        slow = nums[slow];    //moves one step at a time
        fast = nums[nums[fast]];    //moves two steps at a time
    } while (slow != fast);
    slow = nums[0];   //slow back to the start
    while (slow != fast) {
  //Both now move one step at a time
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
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
    int result = findDuplicate(nums);
    cout << "Output: " << result << endl;
    return 0;
}

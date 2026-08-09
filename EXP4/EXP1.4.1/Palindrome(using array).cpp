#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool result = isPalindrome(arr);
    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}  //constructor that automatically makes node and next as null ptr
};
bool isPalindrome(ListNode* head){
    vector<int> vals;   //empty array where the LL values will be stored
    ListNode* curr = head;    //curr: temporary ptr used to walk through the list starting from head
    while (curr != nullptr){
        vals.push_back(curr->val);   //current value grabbed and added to the way
        curr = curr->next;  //move curr fwd
    }
    int left = 0;
    int right = vals.size() - 1;
    while (left < right) {
        if (vals[left] != vals[right]){   //if left value != right value, not palindrome
            return false;
        }
        left++;
        right--;
    }
    return true;   //loop stops when left and right meet or cross
}
ListNode* buildList(int n){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
int main(){
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the node values: ";
    ListNode* head = buildList(n);
    bool result = isPalindrome(head);
    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}

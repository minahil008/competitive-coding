#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};
ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr){
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
bool isPalindrome(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* secondHead = reverseList(slow->next);
    ListNode* p1 = head;
    ListNode* p2 = secondHead;
    bool result = true;
    while (p2 != nullptr){
        if (p1->val != p2->val){
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    slow->next = reverseList(secondHead);
    return result;
}
ListNode* buildList(int n){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        } else{
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

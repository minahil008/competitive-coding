#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* reverseList(ListNode* head){  //this function takes the head and returns new head pointing to same nodes but next nodes flipped (list runs bwd)
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr){
        ListNode* nextTemp = curr->next;  //saves copy of curr's original next pointer cuz later it will be overwritten
        curr->next = prev;  //pointing bwd instead of fwd
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
bool isPalindrome(ListNode* head){
    if (head == nullptr || head->next == nullptr){   //if no or 1 node = automatically palindrome
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;  //moves one step at a time
        fast = fast->next->next;  //moves two steps at a time
    }  //by the time fast is near end, slow will be at the middle
    ListNode* secondHead = reverseList(slow->next);   //slow is at middle, everything after is second half, reverse it (skipping middle cuz slow->next)
    ListNode* p1 = head;   //walks from beginning of original list
    ListNode* p2 = secondHead;  //walks from beginning of new reversed second half
    bool result = true;
    while (p2 != nullptr){
        if (p1->val != p2->val){
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    slow->next = reverseList(secondHead);  //reverse second half again to original
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

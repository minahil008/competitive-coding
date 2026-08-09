#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* odd = head;   //odd value starts as first node
    ListNode* even = head->next;  //even starts at second node
    ListNode* evenHead = even;   //save reference of where even starts to know where to reattach even chain
    while (even != nullptr && even->next != nullptr) {
        odd->next = even->next;   //odd ptr skips over even node and jumps to next odd node
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;  //connects both chains back together
    return head;
}
ListNode* buildList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
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
void printList(ListNode* head) {
    ListNode* curr = head;
    cout << "Output: ";
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    ListNode* head = nullptr;
    if (n > 0) {
        cout << "Enter the node values: ";
        head = buildList(n);
    }
    head = oddEvenList(head);
    printList(head);
    return 0;
}

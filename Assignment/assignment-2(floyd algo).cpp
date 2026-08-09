#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<ListNode*> nodes(n);
    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes[i] = new ListNode(val);
    }
    for (int i = 0; i < n - 1; i++)
        nodes[i]->next = nodes[i + 1];
    int pos;
    cout << "Enter position tail connects to for a cycle: ";
    cin >> pos;
    if (pos != -1)
        nodes[n - 1]->next = nodes[pos];
    Solution sol;
    cout << "Has cycle (Floyd's method): "
         << (sol.hasCycle(nodes[0]) ? "true" : "false") << endl;
    return 0;
}

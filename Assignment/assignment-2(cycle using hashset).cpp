#include <iostream>
#include <unordered_set>
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
        unordered_set<ListNode*> seen;
        while (head) {
            if (seen.count(head)) return true;
            seen.insert(head);
            head = head->next;
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
    cout << "Enter position (0-indexed) tail connects to for a cycle (-1 for no cycle): ";
    cin >> pos;
    if (pos != -1)
        nodes[n - 1]->next = nodes[pos];
    Solution sol;
    cout << "Has cycle: "
         << (sol.hasCycle(nodes[0]) ? "true" : "false") << endl;
    return 0;
}

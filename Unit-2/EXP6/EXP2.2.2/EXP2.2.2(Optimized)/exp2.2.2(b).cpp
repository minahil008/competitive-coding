#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}  //constructor sets things up automatically when a new node is created
};
TreeNode* buildTree(vector<string>& tokens){
    if (tokens.empty() || tokens[0] == "N") return nullptr;   //If the input is empty or the root is "N", the tree is empty
    TreeNode* root = new TreeNode(stoi(tokens[0]));   //converts root string to int using stoi(string to int)
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < tokens.size()){   //for left child
        TreeNode* curr = q.front();
        q.pop();
        if (i < tokens.size() && tokens[i] != "N"){   //for left child
            curr->left = new TreeNode(stoi(tokens[i]));
            q.push(curr->left);
        }
        i++;
        if (i < tokens.size() && tokens[i] != "N"){   //for right
            curr->right = new TreeNode(stoi(tokens[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
TreeNode* findNode(TreeNode* root, int val){    //a recursive dfs
    if (root == nullptr) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left != nullptr) return left;
    return findNode(root->right, val);
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = nullptr;   //tracks the best candidate
    TreeNode* node = root;           //walks down from the root
    while (node != nullptr){
        if (p->val >= node->val){
            node = node->right;
        }else{
            successor = node;
            node = node->left;
        }
    }

    return successor;
}
int main(){
    int n;
    cout << "Enter number of tokens: ";
    cin >> n;
    vector<string> tokens(n);
    cout << "Enter the tokens: ";
    for (int i = 0; i < n; i++){
        cin >> tokens[i];
    }
    TreeNode* root = buildTree(tokens);
    int pVal;
    cout << "Enter value of p: ";
    cin >> pVal;
    TreeNode* p = findNode(root, pVal);
    TreeNode* result = inorderSuccessor(root, p);
    if (result != nullptr){
        cout << "Output: " << result->val << endl;
    } else {
        cout << "Output: null" << endl;
    }
    return 0;
}

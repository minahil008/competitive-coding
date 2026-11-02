#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};
TreeNode* buildTree(vector<string>& tokens){
    if (tokens.empty() || tokens[0] == "N") return nullptr;
    TreeNode* root = new TreeNode(stoi(tokens[0]));   //stoi (converts string to int)
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < tokens.size()){   //Level order means nodes get children in the order they were created
        TreeNode* curr = q.front();
        q.pop();
        if (i < tokens.size() && tokens[i] != "N"){    //for left
            curr->left = new TreeNode(stoi(tokens[i]));
            q.push(curr->left);
        }
        i++;
        if (i < tokens.size() && tokens[i] != "N"){     //for right
            curr->right = new TreeNode(stoi(tokens[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
TreeNode* findNode(TreeNode* root, int val){
    if (root == nullptr) return nullptr;    //node not forund
    if (root->val == val) return root;      //node found
    TreeNode* left = findNode(root->left, val);
    if (left != nullptr) return left;   //node found in left subtree
    return findNode(root->right, val);  //right
}
void inorder(TreeNode* node, vector<TreeNode*>& order){
    if (node == nullptr) return;
    inorder(node->left, order);    //left subtree
    order.push_back(node);         //current node
    inorder(node->right, order);   //right subtree
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    vector<TreeNode*> order;
    inorder(root, order);
    for (int i = 0; i < order.size(); i++){
        if (order[i] == p) {
            if (i + 1 < order.size()){
                return order[i + 1];    //next no. is successor
            }
            return nullptr;    //no sucessor
        }
    }
    return nullptr;
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
    if (result != nullptr) {
        cout << "Output: " << result->val << endl;
    } else {
        cout << "Output: null" << endl;
    }
    return 0;
}

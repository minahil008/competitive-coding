#include <iostream>
#include <vector>
#include <queue>   //building tree level by level
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;  //pointer to this node's left child
    TreeNode* right; //pointer to this node's right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}   //every newly created node starts out as a leaf with no children until we attach some
};
TreeNode* buildTree(vector<string>& tokens){
    if (tokens.empty() || tokens[0] == "N") return nullptr;  //"N" means "no node here"
    TreeNode* root = new TreeNode(stoi(tokens[0]));   //stoi -> string to integer (converts the first token into actual integer)
    queue<TreeNode*> q;  //holds pointers to nodes
    q.push(root);
    int i = 1;    //cuz root (0) is already done
    while (!q.empty() && i < tokens.size()){   //loops until there's still node in the queue waiting to have children and there are still tokens left to read
        TreeNode* curr = q.front();
        q.pop();
        if (i < tokens.size() && tokens[i] != "N"){    //handling curr's left child
            curr->left = new TreeNode(stoi(tokens[i]));
            q.push(curr->left);    //add this child to the queue
        }
        i++;
        if (i < tokens.size() && tokens[i] != "N"){
            curr->right = new TreeNode(stoi(tokens[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q){
    if (root == nullptr || root->val == p || root->val == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr){
        return root;
    }
    return (left != nullptr) ? left : right;
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
    int p, q;
    cout << "Enter value of p: ";
    cin >> p;
    cout << "Enter value of q: ";
    cin >> q;
    TreeNode* result = lowestCommonAncestor(root, p, q);
    cout << "Output: " << result->val << endl;
    return 0;
}

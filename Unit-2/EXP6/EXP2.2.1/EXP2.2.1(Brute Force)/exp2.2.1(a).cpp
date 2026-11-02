#include <iostream>
#include <vector>
#include <queue>   //for level by level construction of tree
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}   //constructor(val = x and both children to nullptr whenever a new node is created)
};
TreeNode* buildTree(vector<string>& tokens){   //tree isn't built in cpp, so this is a helper to construct tree from user i/p
    if (tokens.empty() || tokens[0] == "N") return nullptr;   //N is chosen symbol for null
    TreeNode* root = new TreeNode(stoi(tokens[0]));  //stoi converts a string like "3" into the actual integer 3
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;   //since token 0 is already used for root, start reading from second token
    while (!q.empty() && i < tokens.size()){
        TreeNode* curr = q.front();
        q.pop();
        if (i < tokens.size() && tokens[i] != "N"){   //check next token, if not N then attach to curr's left child
            curr->left = new TreeNode(stoi(tokens[i]));
            q.push(curr->left);
        }
        i++;
        if (i < tokens.size() && tokens[i] != "N"){  //for right child
            curr->right = new TreeNode(stoi(tokens[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
bool findPath(TreeNode* root, int target, vector<TreeNode*>& trail){  //find the path from root down to the node with value target (recording every node)
    if (root == nullptr) return false;
    trail.push_back(root);   //Tentatively add the current node to our path
    if (root->val == target) return true;
    if (findPath(root->left, target, trail) || findPath(root->right, target, trail)){
        return true;
    }
    trail.pop_back();
    return false;
}
TreeNode*LCA(TreeNode* root, int p, int q){
    vector<TreeNode*> path1, path2;
    findPath(root, p, path1);
    findPath(root, q, path2);
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]){
        i++;
    }
    return path1[i - 1];
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
    TreeNode* result = LCA(root, p, q);
    cout << "Output: " << result->val << endl;
    return 0;
}

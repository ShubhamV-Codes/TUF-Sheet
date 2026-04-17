#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Helper function: Inorder traversal (for checking result)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Original tree:
              4
            /   \
           2     7
          / \   / \
         1   3 6   9
    */

    TreeNode* root = new TreeNode(4,
        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
        new TreeNode(7, new TreeNode(6), new TreeNode(9))
    );

    Solution obj;

    cout << "Inorder before invert: ";
    inorder(root);
    cout << endl;

    root = obj.invertTree(root);

    cout << "Inorder after invert: ";
    inorder(root);
    cout << endl;

    return 0;
}
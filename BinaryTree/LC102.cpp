#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();
            vector<int> temp;

            while (len--) {
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};

// Helper function to print result
void printResult(vector<vector<int>> res) {
    for (auto level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    printResult(result);

    return 0;
}
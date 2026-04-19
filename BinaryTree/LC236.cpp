
/*
 * ============================================================
 * PROBLEM  : Lowest Common Ancestor of a Binary Tree
 * PLATFORM : LeetCode 236
 * LEVEL    : Medium
 * ============================================================
 *
 * INTUITION:
 * We use post-order traversal (left → right → root)
 * Each node reports back to its parent:
 *   - "I found p or q"  → return that node
 *   - "I found nothing" → return NULL
 * When a node gets non-NULL from BOTH sides → it is the LCA
 * When a node gets non-NULL from ONE side  → bubble it up to parent
 *
 * BASE CASE TRICK:
 * If root itself is p or q, no need to go deeper
 * Just return root immediately (the other node must be in its subtree or above)
 * This also handles NULL nodes (empty subtree → return NULL)
 *
 * COUNTING LOGIC:
 * left  = result from left subtree  (NULL or a found node)
 * right = result from right subtree (NULL or a found node)
 * total = how many sides found something (0, 1, or 2)
 *   total == 2 → p and q on opposite sides → current root is LCA
 *   total == 1 → only one found            → bubble it up
 *   total == 0 → nothing found             → return NULL
 *
 * TIME COMPLEXITY  : O(N) — visit every node once
 * SPACE COMPLEXITY : O(H) — recursion stack, H = height of tree
 * ============================================================
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        int total = (left != nullptr ? 1 : 0) + (right != nullptr ? 1 : 0);

        if(total == 2)       return root;   // both sides found → LCA is here
        if(left  != nullptr) return left;   // only left found  → bubble up
        if(right != nullptr) return right;  // only right found → bubble up
        return nullptr;                     // nothing found
    }
};

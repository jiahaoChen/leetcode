/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left) return left;
        if (right) return right;
        if (isAncestor(root, p) && isAncestor(root, q)) 
            return root;
        else
            return NULL;
    }
    
    bool isAncestor(TreeNode* root, TreeNode* son)
    {
        if (root == NULL) return false;
        if (root == son || root->left==son || root->right==son) return true;
        return isAncestor(root->left, son) || isAncestor(root->right, son);
    }
};
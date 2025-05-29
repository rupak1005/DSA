class Solution {
public:
    bool isSymmetrichelp(TreeNode* left, TreeNode* right) {
        // Handle NULL cases first
        if (left == nullptr || right == nullptr) {
            return left == right; // True only if both are NULL
        }
        // Compare values, then recurse on mirrored children
        return (left->val == right->val) 
            && isSymmetrichelp(left->left, right->right) 
            && isSymmetrichelp(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetrichelp(root->left, root->right);
    }
};

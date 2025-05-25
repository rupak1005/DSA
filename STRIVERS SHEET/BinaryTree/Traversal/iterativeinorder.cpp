class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Reach the leftmost node of the current node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Current must be nullptr at this point
            curr = st.top();
            st.pop();
            ans.push_back(curr->val); // Visit the node

            // Now, visit the right subtree
            curr = curr->right;
        }

        return ans;
    }
};

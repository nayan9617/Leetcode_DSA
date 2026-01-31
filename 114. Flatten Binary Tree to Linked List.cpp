/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, stack<TreeNode*> &st){
        if(!root) return;
        dfs(root->right, st);
        dfs(root->left, st);
        st.push(root);
    }

    void flatten(TreeNode* root) {
        if(!root) return;

        stack<TreeNode*> st;
        dfs(root, st);

        TreeNode* curr = st.top();
        st.pop();

        while(!st.empty()){
            curr->right = st.top();
            curr->left = nullptr;
            st.pop();
            curr = curr->right;
        }
    }
};
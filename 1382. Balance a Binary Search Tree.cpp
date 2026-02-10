/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.*/

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
    void inorder(TreeNode* root, vector<int>& nodesVal){
        if(!root) return;
        inorder(root->left, nodesVal);
        nodesVal.push_back(root->val);
        inorder(root->right, nodesVal);
    }

    TreeNode* build(int left, int right, vector<int>& nodesVal){
        if(left > right) return nullptr;

        int mid = left + (right - left)/2;
        TreeNode* newBalancedRoot = new TreeNode(nodesVal[mid]);

        newBalancedRoot->left = build(left, mid-1, nodesVal);
        newBalancedRoot->right = build(mid+1, right, nodesVal);

        return newBalancedRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodesVal;
        inorder(root, nodesVal);

        int n = nodesVal.size();
        TreeNode* ans = build(0, n-1, nodesVal);
        return ans;
    }
};3719. Longest Balanced Subarray I

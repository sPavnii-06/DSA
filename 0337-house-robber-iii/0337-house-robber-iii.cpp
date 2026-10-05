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
/**











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
 
    pair<int, int> maxRob(TreeNode* root) {
        if (root == NULL) return {0, 0};

        auto left = maxRob(root->left);
        auto right = maxRob(root->right);

        int rob = root->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {
        pair<int, int> ans = maxRob(root);
        return max(ans.first, ans.second);
    }
};
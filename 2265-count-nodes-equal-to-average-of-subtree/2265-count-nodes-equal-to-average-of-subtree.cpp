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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    std::pair<int, int> dfs(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = dfs(root->left, ans);
        auto [rightSum, rightCount] = dfs(root->right, ans);

        int sum = root->val + leftSum + rightSum;
        int count = 1 + leftCount + rightCount;
        if (sum / count == root->val) {
            ++ans;
        }

        return {sum, count};
    }
};
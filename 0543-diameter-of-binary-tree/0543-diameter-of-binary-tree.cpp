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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
private:
    int diameter(TreeNode* root, int& ans){
        if(root == nullptr) return -1;
        int l = diameter(root->left, ans);
        int r = diameter(root->right, ans);
        ans = max(ans, l + r + 2);
        return max(l+1, r+1);
    }
};
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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        traverse(root, 0, ans);
        return ans;
    }
private:
    void traverse(TreeNode* root, int cnt, int& ans){
        if(root == nullptr){
            ans = max(ans, cnt);
            return;
        }
        traverse(root->left, cnt + 1, ans);
        traverse(root->right, cnt + 1, ans);
    }
};
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
    void dfs(TreeNode* root, vector<vector<int>>& ans){
        if(root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int i = 0;
            int size = q.size();
            vector<int> temp;
            for( ; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
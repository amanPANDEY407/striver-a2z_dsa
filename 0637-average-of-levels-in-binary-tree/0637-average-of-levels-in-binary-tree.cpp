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
    void helper(TreeNode* root, vector<double>& ans){
        if(root == nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int i = 0;
            int size = q.size();
            double sum = 0.0;
            for(; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum = sum + curr->val;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
            double x = sum/size;
            ans.push_back(x);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        helper(root, ans);
        return ans;
    }
};
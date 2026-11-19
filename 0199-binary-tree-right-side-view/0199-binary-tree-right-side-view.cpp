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
    void bfs(TreeNode* root, vector<int> & ans){
        if(root == nullptr) return;

        queue<TreeNode *> q;
        q.push(root);
        int i,size;
        while(!q.empty()){
            i = 0;
            size = q.size();
            for( ; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i == size - 1) ans.push_back(curr->val);
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        bfs(root, ans);
        return ans;
    }
};
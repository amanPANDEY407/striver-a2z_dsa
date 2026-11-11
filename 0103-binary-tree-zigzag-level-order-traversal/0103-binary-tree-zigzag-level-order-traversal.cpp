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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while( !q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                if(q.front()-> left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                if(flag) level[size - 1 - i] = q.front()->val;
                else level[i] = q.front()->val;
                q.pop();
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }

};
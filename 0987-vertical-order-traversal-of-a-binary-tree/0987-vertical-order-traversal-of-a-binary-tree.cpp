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
    void traverse(TreeNode * root, int r, int c, map<int,map<int,multiset<int>>>& mpp){
        if(root == nullptr) return;
        mpp[c][r].insert(root->val);
        traverse(root->left, r + 1 , c - 1 , mpp);
        traverse(root->right, r + 1 , c + 1 , mpp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mpp;
        traverse(root, 0 , 0 , mpp);
        for(auto & [col, rowMap] : mpp){
            vector<int> column;
            for(auto & [row, values] : rowMap){
                for(auto & val : values){
                    column.push_back(val);
                }
            }
            ans.push_back(column);
        }
        return ans;
    }
};
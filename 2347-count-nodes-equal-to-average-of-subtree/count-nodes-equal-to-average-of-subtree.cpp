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
    int matching = 0;
private:
    pair<int,int> solve(TreeNode* root){
        if(root == nullptr) return {0,0};
        pair<int,int> left = solve(root->left); // sum, number of nodes
        pair<int,int> right = solve(root->right);

        if((left.first + right.first + root->val)/(left.second + right.second + 1) == root->val) matching++;
        return {left.first + right.first + root->val, left.second + right.second + 1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return matching;
    }
};
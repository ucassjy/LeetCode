/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(!root)
        return 0;
    
    if(!root->right && !root->left)
        return 1;
        
    int l = maxDepth(root->left) + 1;
    int r = maxDepth(root->right) + 1;
    return l > r?l : r;
}
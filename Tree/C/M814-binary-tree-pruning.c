// time:  O(n)
// space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* pruneTree(struct TreeNode* root) {
    if(root->left)
        root->left = pruneTree(root->left);
    
    if(root->right)
        root->right = pruneTree(root->right);
    
    if(root->val == 0 && !root->left && !root->right)
        return NULL;
    
    return root;
}
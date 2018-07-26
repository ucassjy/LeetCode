// time:  O(n)
// space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void bottomLeft(struct TreeNode* root, int* maxDepth, int* res, int depth){
    if(!root)
        return;
    
    if(depth > *maxDepth){
        *res = root->val;
        *maxDepth = depth;
    }
    
    bottomLeft(root->left, maxDepth, res, depth+1);
    bottomLeft(root->right, maxDepth, res, depth+1);
}
int findBottomLeftValue(struct TreeNode* root) {
    int* maxDepth = (int*)malloc(sizeof(int));
    *maxDepth = 0;
    int* res = (int*)malloc(sizeof(int));
    *res = 0;
    int depth = 1;
    
    bottomLeft(root, maxDepth, res, depth);
    return *res;
}

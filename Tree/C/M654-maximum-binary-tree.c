/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    int i;
    int m = -1;
    int mi = -1;
    for(i = 0; i < numsSize; i++){
        if(nums[i] > m){
            m = nums[i];
            mi = i;
        }
    }
    
    struct TreeNode *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    t->val = m;
    if(mi == 0)
        t->left = NULL;
    else{
        int ln[mi];
        for(i = 0; i < mi; i++)
            ln[i] = nums[i];
        t->left = constructMaximumBinaryTree(ln, i);
    }
    if(mi == numsSize - 1)
        t->right = NULL;
    else{
        int rn[numsSize - mi - 1];
        for(i = 0; i < numsSize - mi - 1; i++)
            rn[i] = nums[mi + i + 1];
        t->right = constructMaximumBinaryTree(rn, i);
    }
    
    return t;
}
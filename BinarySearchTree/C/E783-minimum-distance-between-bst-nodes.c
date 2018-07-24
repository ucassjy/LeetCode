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

void treeToNums(struct TreeNode* root, int* nums, int* i){
    if(root->left)
        treeToNums(root->left, nums, i);
    
    nums[*i] = root->val;
    (*i)++;
    
    if(root->right)
        treeToNums(root->right, nums, i);
}
int minDiffInBST(struct TreeNode* root) {
    int* nums = (int*)malloc(100 * sizeof(int));
    int* i = (int*)malloc(sizeof(int));
    *i = 0;
    treeToNums(root, nums, i);
    
    int m = 65536;
    for(int j = 0; j < (*i)-1; j++){
        int t1 = nums[j+1] - nums[j];
        m = t1<m ? t1 : m;
    }
    return m;
}
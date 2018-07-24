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
void treeToNums(struct TreeNode* root, int* nums, int* i){
    if(root->left)
        treeToNums(root->left, nums, i);
    
    nums[*i] = root->val;
    (*i)++;
    
    if(root->right)
        treeToNums(root->right, nums, i);
}
int getMinimumDifference(struct TreeNode* root) {
    int* nums = (int*)malloc(32768 * sizeof(int));
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

// faster solution
int findleft(struct TreeNode* root)
{
    if(root == NULL)
        return -1;
    while(root->left != NULL)
        root = root->left;
    return root->val;
}
int findright(struct TreeNode* root)
{
    if(root == NULL)
        return -1;
    while(root->right != NULL)
        root = root->right;
    return root->val;
}

int getMinimumDifference(struct TreeNode* root) {
    if(root == NULL)
        return -1;
    int min = -1;
    int rnum = findleft(root->right);
    int lnum = findright(root->left);
    if(rnum != -1)
        min = rnum - root->val;
    if(lnum != -1)
        min = (min > root->val - lnum) ? root->val-lnum : ((min == -1) ? root->val-lnum : min);
    int rmin = getMinimumDifference(root->right);
    int lmin = getMinimumDifference(root->left);
    if(rmin != -1)
        min = (min < rmin) ? min : rmin;
    if(lmin != -1)
        min = (min < lmin) ? min : lmin;
    return min;
}

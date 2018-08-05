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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int depth = 0;
    struct TreeNode** nl = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    nl[0] = root;
    int cur_size, next_size;
    int* res = (int*)malloc(sizeof(int));
    cur_size = 1;
    
    while(cur_size){
        depth++;
        next_size = 0;
        int tv = INT_MIN;
        struct TreeNode** tn = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        
        for(int i = 0; i < cur_size; i++){
            if(nl[i]->val > tv)
                tv = nl[i]->val;
            if(nl[i]->left){
                next_size++;
                tn = realloc(tn, next_size * sizeof(struct TreeNode*));
                tn[next_size-1] = nl[i]->left;
            }
            if(nl[i]->right){
                next_size++;
                tn = realloc(tn, next_size * sizeof(struct TreeNode*));
                tn[next_size-1] = nl[i]->right;
            }
        }
        
        res = realloc(res, depth * sizeof(int));
        res[depth-1] = tv;
        cur_size = next_size;
        nl = tn;
    }
    
    *returnSize = depth;
    return res;
}
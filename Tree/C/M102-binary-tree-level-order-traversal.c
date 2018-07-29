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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int depth = 0;
    struct TreeNode** nl = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    nl[0] = root;
    *columnSizes = (int*)malloc(sizeof(int));
    int cur_size, next_size;
    int** res = (int**)malloc(sizeof(int*));
    cur_size = 1;
    
    while(cur_size){
        depth++;
        *columnSizes = realloc(*columnSizes, depth * sizeof(int));
        (*columnSizes)[depth-1] = cur_size;
        next_size = 0;
        int* tv = (int*)malloc(cur_size * sizeof(int));
        struct TreeNode** tn = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        
        for(int i = 0; i < cur_size; i++){
            tv[i] = nl[i]->val;
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
        
        res = realloc(res, depth * sizeof(int*));
        res[depth-1] = tv;
        cur_size = next_size;
        nl = tn;
    }
    
    *returnSize = depth;
    return res;
}

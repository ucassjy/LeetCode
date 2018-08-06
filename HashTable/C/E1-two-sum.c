// time:  O(n)
// space: O(n)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    typedef struct node{
        int key;
        int val;
    }node;
    node** ht = (node**)calloc(numsSize, sizeof(node*));
    int* ht_size = (int*)calloc(numsSize, sizeof(int));
    int* res = (int*)calloc(2, sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        int pos = abs(nums[i]) % numsSize;
        if(ht_size[pos] && ht[pos])
            for(int j = 0; j < ht_size[pos]; j++)
                if(ht[pos][j].val + nums[i] == target){
                    res[0] = ht[pos][j].key;
                    res[1] = i;
                    return res;
                }
        
        int t1 = abs(target - nums[i]) % numsSize;
        ht_size[t1]++;
        if(ht_size[t1] == 1)
            ht[t1] = (node*)calloc(1, sizeof(node));
        else ht[t1] = realloc(ht[t1], ht_size[t1] * sizeof(node));
        ht[t1][ht_size[t1] - 1].key = i;
        ht[t1][ht_size[t1] - 1].val = nums[i];
    }
    return res;
}
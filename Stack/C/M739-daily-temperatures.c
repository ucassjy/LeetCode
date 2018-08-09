// time:  O(n)
// space: O(n)

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* res = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    int* st = calloc(temperaturesSize, sizeof(int));
    int ind = 0;
    int j = 0;
    for(int i = 0; i < temperaturesSize; i++){
        while(ind > 0 && temperatures[st[ind-1]] < temperatures[i]){
            j = st[--ind];
            res[j] = i - j;
        }
        st[ind] = i;
        ind++;
    }
    return res;
}

// faster solution

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *stack, top, i, *res;
    
    res = (int *)malloc(sizeof(int)*temperaturesSize);
    memset(res, 0, sizeof(int)*temperaturesSize);
    
    stack = (int *)malloc(sizeof(int)*temperaturesSize);
    top = -1;
    *returnSize = temperaturesSize;
    
    for (i=1; i<temperaturesSize; ++i) {
        if (temperatures[i] <= temperatures[i-1]) {
            stack[++top] = i-1;
        } else {
            res[i-1] = 1;
            while (top >= 0 && temperatures[stack[top]] < temperatures[i]) {
                res[stack[top]] = i - stack[top];
                --top;
            }
        }
    }
    
    return res;
}
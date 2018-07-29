// time:  O(n^2)
// space: O(n^2)

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes, int* returnSize) {
    int* ind = (int*)malloc(numCourses * sizeof(int));
    int** oud = (int**)malloc(numCourses * sizeof(int*));
    
    memset(ind, 0, numCourses * sizeof(int));
    for(int i = 0; i < numCourses; i++){
        oud[i] = (int*)malloc(numCourses * sizeof(int));
        memset(oud[i], 0, numCourses * sizeof(int));
    }
    
    for(int i = 0; i < prerequisitesRowSize; i++){
        ind[prerequisites[i][0]] += 1;
        oud[prerequisites[i][1]][prerequisites[i][0]] = 1;
    }
    
    int* res = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    int* tmp = (int*)malloc(numCourses * sizeof(int));
    int top = 0;
    
    for(int i = 0; i < numCourses; i++){
        if(ind[i] == 0){
            res[count] = i;  count++;
            tmp[top] = i;  top++;
        }
    }
    
    while(top != 0){
        top--;
        int t1 = tmp[top];
        for(int i = 0; i < numCourses; i++){
            if(oud[t1][i]){
                ind[i] -= 1;
                if(ind[i] == 0){
                    res[count] = i;  count++;
                    tmp[top] = i;  top++;
                }
            }
        }
    }
    
    *returnSize = count == numCourses?count : 0;
    return res;
}

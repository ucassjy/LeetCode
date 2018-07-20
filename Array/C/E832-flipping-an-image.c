// time:  O(n)
// space: O(n）

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int **res = (int**)malloc(ARowSize * sizeof(int*));
    *columnSizes = (int*)malloc(ARowSize * sizeof(int));
    *returnSize = ARowSize;
    int i, j;
    for(i = 0; i < ARowSize; i++){
        (*columnSizes)[i] = AColSizes[i];
        res[i] = (int*)malloc(AColSizes[i] * sizeof(int));
        for(j = 0; j < AColSizes[i]; j++){
            res[i][j] = 1 - A[i][AColSizes[i] - j - 1];
        }
    }
    return res;
}

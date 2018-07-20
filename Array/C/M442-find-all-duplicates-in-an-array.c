// time:  O(n)
// space: O(1)

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int i;
	
    for(i = 0; i < numsSize; i++){
        nums[(nums[i] - 1 + numsSize) % numsSize] += numsSize;
    }
    
	*returnSize = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] > 2 * numsSize){
            nums[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }
    return nums;
}

// I ignored the condition that every element would appear either once or twice, so
// I just find out all elements that appear more than once. This solution is more simple.

int* findDuplicates(int * nums, int numsSize, int * returnSize){
	int i, j;
	int* answer = (int*) malloc((numsSize >> 1) * sizeof(int));
	*returnSize = 0;

	for (i = 0; i < numsSize; ++i) {
		j = abs(nums[i]) - 1;

		if (nums[j] < 0){
			answer[(*returnSize)] = j + 1;
			(*returnSize)++;
		} else {
			nums[j] = -nums[j];
		}
	}
	return answer;
}

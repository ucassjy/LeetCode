// time:  O(n)
// space: O(1)

int firstMissingPositive(int* nums, int numsSize) {
    if(numsSize == 0) return 1;
    int numsi = 0;
    numsSize++;
    for(int i = 0; i < numsSize-1; i++)
        if(nums[i] < 0 || nums[i] >= numsSize)
            nums[i] = 0;
    
    for(int i = 0; i < numsSize-1; i++)
        if(nums[i] % numsSize < numsSize-1)
            nums[nums[i] % numsSize] += numsSize;
        else numsi += numsSize;
        
    for(int i = 1; i < numsSize-1; i++)
        if(nums[i] / numsSize == 0)
            return i;
    if(numsi / numsSize == 0)
        return numsSize - 1;
    return numsSize;
}
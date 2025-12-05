int removeDuplicates(int* nums, int numsSize) {
    int j=1;
    if(numsSize <= 2) return numsSize;
    for(int i=2; i<numsSize; i++) {
        if(nums[i]!=nums[j] || nums[i]!=nums[j-1]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j+1;
}
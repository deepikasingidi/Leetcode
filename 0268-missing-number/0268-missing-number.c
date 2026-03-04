int missingNumber(int* nums, int numsSize) {
    int sum = 0,sumn;
    for(int j=0; j<numsSize; j++){
        sum += nums[j];
    }
    sumn = (numsSize*(numsSize+1))/2;
    int ans = sumn - sum;
    return ans;
}
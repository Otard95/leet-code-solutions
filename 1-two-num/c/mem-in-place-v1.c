/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* answer = malloc(sizeof(int)*2);
    if (answer == NULL) return NULL;

    *returnSize = 2;

    for (int i = 0; i < numsSize-1; i++) {
      for (int j = i+1; j < numsSize; j++) {
        if (nums[i] + nums[j] == target) {
          answer[0] = i; answer[1] = j;
          break;
        }
      }
    }

    return answer;
}

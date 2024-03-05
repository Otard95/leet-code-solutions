#include <stdlib.h>

double median(int* nums, int numsSize) {
  if (numsSize % 2 == 0) {
    return (double)(nums[(int)(numsSize / 2 - 1)] + nums[(int)(numsSize / 2)]) / 2;
  } else {
    return nums[(int)(numsSize / 2)];
  }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  if (nums1Size == 0) {
    return median(nums2, nums2Size);
  } else if (nums2Size == 0) {
    return median(nums1, nums1Size);
  }

  int total_len = nums1Size + nums2Size;
  // Add 1 to len if total is even as we need the two middle numbers in that case.
  int half_len = total_len / 2 + 1;

  size_t i1 = 0, i2 = 0;
  int last = 0, second_to_last = 0;

  for (int i = 0; i < half_len; i++) {
    second_to_last = last;
    if (i1 >= nums1Size) {
      last = nums2[i2];
      i2++;
      continue;
    }
    if (i2 >= nums2Size) {
      last = nums1[i1];
      i1++;
      continue;
    }
    if (nums1[i1] < nums2[i2]) {
      last = nums1[i1];
      i1++;
      continue;
    } else {
      last = nums2[i2];
      i2++;
      continue;
    }
  }

  if (total_len % 2 == 0) {
    return (double)(second_to_last + last) / 2;
  } else {
    return last;
  }
}

#include <stdio.h>

int main(void) {
  double ans;

  int a1[2] = { 1, 3 };
  int b1[1] = { 2 };
  ans = findMedianSortedArrays(a1, 2, b1, 1);
  printf("%f\n", ans);

  int a2[2] = { 1, 2 };
  int b2[2] = { 3, 4 };
  ans = findMedianSortedArrays(a2, 2, b2, 2);
  printf("%f\n", ans);

  return 0;
}

#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int total_len = nums1Size + nums2Size;
  // Add 1 to len if total is even as we need the two middle numbers in that case.
  int half_len = total_len / 2 + (1 - (total_len % 2));

  // Merge arrays up to half_len
  int* merged = malloc(sizeof(int) * half_len);

  size_t i1 = 0, i2 = 0;

  for (size_t i = 0; i < half_len; i++) {

  }
}

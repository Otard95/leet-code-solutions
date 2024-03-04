#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int total_len = nums1Size + nums2Size;
  // Add 1 to len if total is even as we need the two middle numbers in that case.
  int half_len = total_len / 2 + 1;

  printf("len=%i | hlen=%i | off=%i | odd=%i\n", total_len, half_len, (2 - (total_len % 2)), (total_len % 2));

  size_t i1 = 0, i2 = 0;
  int last[2] = {0};
  int second_to_last[2] = {0};

  for (int i = 0; i < half_len; i++) {
    printf("i=%i\n", i);
    second_to_last[0] = last[0];
    second_to_last[1] = last[1];
    if (i1 >= nums1Size) {
      last[0] = 2;
      last[1] = nums2[i2];
      i2++;
      continue;
    }
    if (i2 >= nums2Size) {
      last[0] = 1;
      last[1] = nums1[i1];
      i1++;
      continue;
    }
    if (nums1[i1] < nums2[i2]) {
      last[0] = 1;
      last[1] = nums1[i1];
      i1++;
      continue;
    } else {
      last[0] = 2;
      last[1] = nums2[i2];
      i2++;
      continue;
    }
  }

  printf("sl=%i | l=%i\n", second_to_last[1], last[1]);
  if (total_len % 2 == 0) {
    return (double)(second_to_last[1] + last[1]) / 2;
  } else {
    return last[1];
  }
}

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

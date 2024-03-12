#include <assert.h>
#include <stdio.h>

#pragma GCC optimize (-O3, -flto, -ffast-math, -march=native, -mtune=native)

int max(int a, int b) {
  return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
  int last[128] = { [0 ... 127] = -1 };
  int longest = 0;
  int last_dup = -1;

  int i = 0;
  while (s[i] != 0) {
    if (longest < i-max(last[s[i]], last_dup)) {
      longest = i-max(last[s[i]], last_dup);
    }
    if (last[s[i]] > last_dup) {
      last_dup = last[s[i]];
    }
    last[s[i]] = i;
    i++;
  }

  return longest;
}

int main(void) {
  int len;

  len = lengthOfLongestSubstring("abcabcbb");
  printf("%d\n", len);
  assert(len == 3);

  len = lengthOfLongestSubstring("bbbbb");
  printf("%d\n", len);
  assert(len == 1);

  len = lengthOfLongestSubstring("pwwkew");
  printf("%d\n", len);
  assert(len == 3);

  len = lengthOfLongestSubstring("au");
  printf("%d\n", len);
  assert(len == 2);

  len = lengthOfLongestSubstring("abcabcd");
  printf("%d\n", len);
  assert(len == 4);

  len = lengthOfLongestSubstring("dvdf");
  printf("%d\n", len);
  assert(len == 3);

  return 0;
}

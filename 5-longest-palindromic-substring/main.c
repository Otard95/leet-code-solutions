#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool is_palindrome(char* cstr, size_t start, size_t end) {
  size_t len = (end - start);
  for (size_t i = 0; i <= len / 2; i++) {
    if (cstr[i + start] != cstr[end - i])
      return false;
  }
  return true;
}

char* longestPalindrome(char* s) {
  printf("Find largest palindrome substr in: %s\n", s);
  size_t len = strlen(s), longest_start = 0, longest_end = 0;

  for (size_t i = 0; i < len; i++) {
    if (len - i < longest_end - longest_start) break;
    for (size_t j = len - 1; j > i; j--) {
      if (j - i < longest_end - longest_start) break;
      printf("%zu %zu\n", i, j);
      if (is_palindrome(s, i, j)) {
        longest_start = i;
        longest_end = j;
      }
    }
  }

  s[longest_end + 1] = 0;
  return s + longest_start;
}

int main(void) {
  char s1[] = "babad";
  char* ans = longestPalindrome(s1);
  printf("%s\n", ans);

  return 0;
}
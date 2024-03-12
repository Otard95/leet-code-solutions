#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
  // If we're not mesing with lines the string doesn't change
  if (numRows == 1) return s;

  size_t len = strlen(s);
  if (numRows > len) return s;

  // abc0
  // 0123

  char* out = malloc(sizeof(char) * len+1);
  if (out == NULL) return NULL;
  out[len] = 0;

  size_t out_i = 0, max_jump = (numRows - 1) * 2, jumps[2] = {0};

  for (size_t l = 0; l < numRows; l++) {
    jumps[0] = max_jump - (l * 2);
    jumps[1] = max_jump - jumps[0];
    if (jumps[0] == 0 || jumps[1] == 0) {
      jumps[0] = max_jump;
      jumps[1] = max_jump;
    }

    size_t jump = 0, i = l;

    while (i < len) {
      out[out_i++] = s[i];
      i += jumps[jump];
      jump = (jump + 1) % 2;
    }
  }

  return out;
}

#include <stdio.h>

int main(void) {
  char* ans;
  ans = convert("abcdefghijklmnopqrstuvwxyz", 3);
  printf("\n%s\n", ans);
  free(ans);
  ans = convert("abcdefghijklmnopqrstuvwxyz", 4);
  printf("\n%s\n", ans);
  free(ans);
  ans = convert("abcdefghijklmnopqrstuvwxyz", 5);
  printf("\n%s\n", ans);
  free(ans);
}

/*
 1 1
 2 2
 3 4
 4 6
 5 8
 6 10
 7 12

 (x - 1) * 2
 ---
 Criteria:
   x > 1
*/
// abcdefghijklmnop
// l 6
// j 10 8-2 6-4 4-6 2-8 10
//
// a    k
// b   jl
// c  i m
// d h  n
// eg   o
// f    p
//
// abcdefghijklmnop
// l 5
// j 8 6-2 4-4 2-6 8
//
// a   i
// b  hj  p
// c g k o
// df  ln
// e   m
//
// PAYPALISHIRING
// l 4
// j 6 4-2 2-4 6
//
// P  I  N
// A LS IG
// YA HR
// P  I
//
// PAYPALISHIRING
// l 3
// j 4 2-2 4
//
// P A H N
// APLSIIG
// Y I R
//
// PAYPALISH
// l 2
// j 2 2
//
// PYPLS
// APAIH
//
// PAYPALISH
// l 1
// j 1
//
// PAYPALISH

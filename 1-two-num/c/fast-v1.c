/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int key;
  int value;
  bool used;
} Entry;

size_t index_from_int(int x, size_t table_size) {
  return (size_t) x % table_size;
}

bool has(Entry* table, size_t table_size, int key) {
  size_t i = index_from_int(key, table_size);
  size_t start = i;

  while (table[i].used) {
    if (table[i].key == key) return true;
    i = (i + 1) % table_size;
    if (i == start) break;
  }

  return false;
}

int get(Entry* table, size_t table_size, int key) {
  size_t i = index_from_int(key, table_size);
  size_t start = i;

  while (table[i].used) {
    if (table[i].key == key) return table[i].value;
    i = (i + 1) % table_size;
    if (i == start) break;
  }

  return NULL;
}

bool set(Entry* table, size_t table_size, int key, int value) {
  size_t i = index_from_int(key, table_size);
  size_t start = i;

  while (table[i].used) {
    i = (i + 1) % table_size;
    if (i == start) return false;
  }

  table[i].key = key;
  table[i].value = value;
  table[i].used = true;

  return true;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* answer = malloc(sizeof(int)*2);
    if (answer == NULL) return NULL;

    int table_size = numsSize*3;
    Entry* table = calloc(table_size, sizeof(Entry));
    if (table == NULL) {
      free(answer);
      return NULL;
    }

    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
      if (has(table, table_size, nums[i])) {
        int other_index = get(table, table_size, nums[i]);
        answer[0] = other_index; answer[1] = i;
        break;
      }

      set(table, table_size, target - nums[i], i);
    }

    free(table);

    return answer;
}

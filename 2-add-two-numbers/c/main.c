#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int get_value(struct ListNode* node) {
  if (node == NULL) return 0;
  return node->val;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  static int carry, sum, rem;
  static struct ListNode *d1, *d2, *p_last, *result, *carry_node;

  carry = 0;
  d1 = l1;
  d2 = l2;

  while (d1 != NULL || d2 != NULL) {
    sum = get_value(d1) + get_value(d2) + carry;
    rem = sum % 10;

    if (d1 != NULL) {
      d1->val = rem;
      result = l1;
      p_last = d1;
      d1 = d1->next;
    }
    if (d2 != NULL) {
      d2->val = rem;
      result = l2;
      p_last = d2;
      d2 = d2->next;
    }

    carry = sum / 10;
  }

  if (carry > 0) {
    carry_node = malloc(sizeof(struct ListNode));
    if (carry_node == NULL) return NULL;

    carry_node->val = carry;
    carry_node->next = NULL;

    p_last->next = carry_node;
  }

  return result;
}

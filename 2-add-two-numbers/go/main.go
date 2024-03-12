package main

type ListNode struct {
    Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
  carry := 0;
  head := &ListNode{}

  for node := head; l1 != nil || l2 != nil || carry > 0; node = node.Next {
    sum := carry
    if l1 != nil {
      sum += l1.Val
      l1 = l1.Next
    }
    if l2 != nil {
      sum += l2.Val
      l2 = l2.Next
    }

    node.Next = &ListNode{Val: sum % 10}
    carry = sum / 10
  }

  return head.Next
}

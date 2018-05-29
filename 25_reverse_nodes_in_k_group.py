# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        cur = head
        head = tail = ListNode(0)
        while cur:
            last_tail, tail = tail, cur
            for _ in range(k):
                if cur is None:  # not enough k, reverse it again to remain as it is
                    cur = last_tail.next
                    last_tail.next = None
                    while cur:
                        cur.next, cur, last_tail.next = last_tail.next, cur.next, cur
                    break
                cur.next, cur, last_tail.next = last_tail.next, cur.next, cur
        return head.next

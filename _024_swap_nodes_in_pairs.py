# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return

        node = ListNode(0)
        node.next = head
        head = node

        while node.next and node.next.next:

            first = node.next
            second = first.next
            node.next, first.next, second.next = second, second.next, first

            node = first

        return head.next

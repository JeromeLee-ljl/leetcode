# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """

        # def remove(head, n):
        #     if not head.next:
        #         return 1
        #     nth_end = remove(head.next, n)
        #     if nth_end == n:
        #         head.next = head.next.next
        #     return nth_end+1
        #
        # node = ListNode(None)
        # node.next = head
        # remove(node,n)
        # return node.next

        fast = slow = head
        for i in range(n):
            fast = fast.next
        if not fast:
            return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next

        return head


def printList(head):
    while head:
        print(head.val)
        head = head.next
    print()

if __name__ == '__main__':
    head = ListNode(1)
    node = head
    node.next = ListNode(2)
    node = node.next
    node.next = ListNode(3)
    node = node.next
    node.next = ListNode(4)
    node = node.next
    node.next = ListNode(5)
    node = node.next
    node.next = ListNode(6)
    node = node.next

    printList(head)
    head = Solution().removeNthFromEnd(head, 2)
    printList(head)


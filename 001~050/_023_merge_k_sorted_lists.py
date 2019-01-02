# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        def merge(node1, node2):
            head = node = ListNode(0)
            while node1 and node2:
                if node1.val <= node2.val:
                    node.next = node1
                    node1 = node1.next
                else:
                    node.next = node2
                    node2 = node2.next
                node = node.next
            node.next = node1 or node2
            return head.next

        length = len(lists)
        if length == 0:
            return None
        elif length == 1:
            return lists[0]
        else:
            node1 = self.mergeKLists(lists[:length // 2])
            node2 = self.mergeKLists(lists[length // 2:])
            return merge(node1, node2)

        # lists = list(filter(lambda x: x, lists))
        # if len(lists) == 0: return None
        #
        # lists.sort(key=lambda x: x.val)
        #
        # head = node = ListNode(0)
        # while True:
        #     if len(lists) == 0 or lists[0] is None: break
        #     node.next = lists[0]
        #     node = node.next
        #     lists[0] = lists[0].next
        #
        #     # if lists[0] is None:
        #     #     lists.pop(0)
        #     # else:
        #     #     lists.sort(key=lambda x: x.val)
        #     #
        #     node_other = lists.pop(0)
        #     if node_other is None:
        #         continue
        #     for i in range(len(lists)):
        #         if lists[i].val >= node_other.val:
        #             lists.insert(i, node_other)
        #             break
        #         if i == len(lists) - 1:
        #             lists.append(node_other)
        # return head.next


if __name__ == '__main__':
    # a = [ListNode(0), ListNode(2), ListNode(1)]
    a = [None]

    Solution().mergeKLists(a)

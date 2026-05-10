# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        ptr = tmp = head

        for _ in range(n):
            ptr = ptr.next
        
        if not ptr:
            return head.next

        while ptr.next:
            ptr = ptr.next
            tmp = tmp.next
        
        tmp.next = tmp.next.next
        return head
        
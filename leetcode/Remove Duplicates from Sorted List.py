class Solution(object):
    def deleteDuplicates(self, head):
        last = None
        new_head = ListNode(0)
        new_tail = new_head
        while head:
            if last == None or last != head.val:
                new_tail.next = ListNode(head.val)
                new_tail = new_tail.next
                
            last = head.val
            head = head.next

        return new_head.next


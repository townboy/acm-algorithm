
class Solution:
    def addTwoNumbers(self, a, b):

        def add_tail(node, val):
            node.next = ListNode(val)
            return node.next
        
        head = ListNode(0)
        tail = head 
        add = 0
        while a or b:
            aa = a.val if a else 0
            bb = b.val if b else 0
            nowval = (aa + bb + add) % 10
            add = (aa + bb + add) / 10
            tail = add_tail(tail, nowval)
            
            a = a.next if a else None
            b = b.next if b else None

        if 0 != add:
            tail = add_tail(tail, add)
            
        return head.next



#! /usr/bin/env
# Definition for singly-linked list.
class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
  def deleteDuplicates(self, head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    if head == None:
      return None
    
    newhead = ListNode("not num")
    newroot = newhead
    
    
    flg = False
    tmp = head.val
    head = head.next
    
    while head != None:
      if tmp != head.val:
        if not flg:
          newhead.next = ListNode(tmp)
          newhead = newhead.next
        tmp = head.val
        flg = False
      else:
        # print(tmp)
        flg = True
      head = head.next
    
    if not flg:
      newhead.next = ListNode(tmp)
      # newhead = newhead.next
      
    
    return newroot.next



a = Solution()

b = ListNode(1)
b.next = ListNode(2)
root = b
b = b.next
b.next= ListNode(3)
b = b.next
b.next = ListNode(3)
b = b.next
b.next = ListNode(4)
b = b.next
b.next = ListNode(4)
b = b.next
b.next = ListNode(5)
c = a.deleteDuplicates(root)
print()
while c != None:
  print(c.val)
  c = c.next
        
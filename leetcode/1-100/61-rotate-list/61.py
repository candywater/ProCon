#! /usr/bin/env python3


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def show(head, count):
  for i in range(count):
    if head == None: 
      return
    print(head.val)
    head = head.next
  print()

# いい方法思いついたよー
class Solution:
  def rotateRight(self, head, k):
    """
    :type head: ListNode
    :type k: int
    :rtype: ListNode
    """
    # count = 0
    if head == None:
      return None
    # count = 1
    if head.next == None:
      return head

    # count > 2
    root = head
    count = 1
    while(head.next != None):
      head = head.next
      count += 1    
    head.next = root
    # right 2 left
    k = count - k % count
    
    #show(root, count) # debug
    
    head = root
    for i in range(k):
      # print( head.val )
      head = head.next
    root = head
    # print("root: " + str(root.val) )
    #show(root, count) # debug

    for i in range(count-1):
      # print( head.val )
      head = head.next
    head.next = None
    
    #show(root, count) # debug
    print()
    
    return root
      
'''
# count = 2
if head.next.next == None:
if k % 2 == 0:
  return head
else:
  root = head.next
  head.next = None
  root.next = head
  return root
###
'''

a = Solution
b = ListNode(1)
c = b

b.next = ListNode(2)
b = b.next
b.next = ListNode(3)
b = b.next
b.next = ListNode(4)
b = b.next
b.next = ListNode(5)
b = b.next

show(a.rotateRight(a, c, 2), 5)
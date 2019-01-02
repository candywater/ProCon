/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
"use strict";



var addNode = function(head, val){
  if(head == null){
    return new ListNode(val);
  }    
  else{
    head.next = new ListNode(val);
    return head.next;
  }
}

var partition = function(head, x) {
  if(head == null) 
    return head;
  
  var lessHead = null;
  var greaterHead = null;
  var lessRoot = null;
  var greaterRoot = null;
  
  while(head != null){
    if(head.val < x){
      lessHead = addNode(lessHead, head.val);
      if(lessRoot == null)
        lessRoot = lessHead;
    }
    else{
      greaterHead = addNode(greaterHead, head.val);
      if(greaterRoot == null)
        greaterRoot = greaterHead;
    }
    head = head.next;
  }
  if(lessHead != null)
    lessHead.next = greaterRoot;
  else
    lessRoot = greaterRoot;
  return lessRoot;  
};
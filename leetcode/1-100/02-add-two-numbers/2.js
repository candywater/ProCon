/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var a = consStr("",l1)
    var b = consStr("",l2)

    var c = plusstr(a,b)
    c= "" + c
    var res = new ListNode(parseInt(c[c.length-1]))
    var head = res
    var tmp
    for(var i = 2; i <= c.length; i++){
        tmp = new ListNode(parseInt(c[c.length-i]))
        res.next = tmp
        res = tmp
    }
    return head
};

function plusstr(a,b){
    var len = a.length > b.length ? a.length : b.length
    var res = ""
    var c = 0
    var over = 0
    for(var i = 1; i <= len; i++){
        var numa= i <= a.length ? parseInt(a[a.length-i]) : 0
        var numb= i <= b.length ? parseInt(b[b.length-i]) : 0

        c = numa + numb + over
        over = 0
        over = Math.floor(c/10)
        //console.log("c;"+c)
        c = c % 10
        res = "" + c + res
        //console.log("a:"+numa+" b:"+numb+" c:"+c+" over:"+over + "   c/10:"+(c/10).toFixed())
    }
    res = over == 0 ? res : over + res
    return res
}

function consStr(a = "",l1){
  for(var i = 0; l1.next != null; l1 = l1.next){
        a = l1.val+a
  }
  a = l1.val+a;
  return (a)
}

/*function ListNode(val){
    this.val=val
    this.next=null;
}*/

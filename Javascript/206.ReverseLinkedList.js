/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
  if (!head || !head.next) return head;
  var pre = null;
  var cur = head;
  var next = head.next;
  while (cur) {
    cur.next = pre;
    pre = cur;
    cur = next;
    if (!next)
      break;
    next = next.next;
  }
  return pre;
};
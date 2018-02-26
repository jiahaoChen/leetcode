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

function revert(l) {
  let pre = null;
  let cur = l;
  let next = l.next;
  while (cur != null) {
    cur.next = pre;
    pre = cur;
    cur = next;
    if (next)
      next = next.next;
  }
  return pre;
}

var addTwoNumbers = function(l1, l2) {
  let i = 0;
  let one = 0;
  var long = {};
  var short = {};
  let m = 0;
  let n = 0;
  for (let p = l1; p != null; p = p.next) {
    m++;
  }
  for (let p = l2; p != null; p = p.next) {
    n++;
  }
  
  if (m > n) {
    long = l1;
    short = l2;
  } else {
    long = l2;
    short = l1;
  }  
  
  // long = revert(long);
  // short = revert(short);
  pShort = short;
  pLong = long;
  while(pShort) {
    let sum = (pLong.val + pShort.val + one);
    pLong.val = sum % 10;
    one = Math.floor(sum / 10);
    if (!pShort.next)
      break;
    pLong = pLong.next;
    pShort = pShort.next;
  }
  while (pLong) {
    if(!pLong.next)
      break;
    pLong = pLong.next;
    let sum = (pLong.val + one);
    pLong.val = sum % 10;
    one = Math.floor(sum / 10);
  }
  if (one)
    pLong.next = new ListNode(one)
  
  return long
};
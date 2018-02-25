/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
function findKth(nums1, nums2, k) {
  // console.log('nums1: ' + nums1)
  // console.log('nums2: ' + nums2)
  // console.log('k: ' + k)
  let m = nums1.length;
  let n = nums2.length;
  
  if (m == 0)
    return nums2[k-1];
  if (n == 0)
    return nums1[k-1];
  if (k == 1)
    return Math.min(nums1[0], nums2[0])
  
  var a = m >= Math.floor(k/2)? nums1[Math.floor(k/2)-1]: null
  var b = n >= Math.floor(k/2)? nums2[Math.floor(k/2)-1]: null
  if (b == null || (a != null && a < b))
    return findKth(nums1.slice(Math.floor(k/2)), nums2, k-Math.floor(k/2))
  else
    return findKth(nums1, nums2.slice(Math.floor(k/2)), k-Math.floor(k/2))
}
var findMedianSortedArrays = function(nums1, nums2) {
  var total = nums1.length + nums2.length;
  var k = Math.floor(total/2)
  if (total%2 != 0) {
    return findKth(nums1, nums2, k + 1);
  } else {
    return (findKth(nums1, nums2, k) + findKth(nums1, nums2, k + 1)) / 2;
  }
};
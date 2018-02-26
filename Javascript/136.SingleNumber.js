/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  var ret = 0;
  for (let i = 0; i < nums.length; ++i) {
    ret = ret^nums[i];
  }
  return ret;
};
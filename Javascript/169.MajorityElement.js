/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
  var hit = {}
  for (let i = 0; i < nums.length; ++i) {
    if(nums[i] in hit) hit[nums[i]]++;
    else hit[nums[i]] = 1;
    if (hit[nums[i]] > (nums.length/2))
      return nums[i];
  }
  return null;
};
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

var twoSum = function(nums, target) {
  let hit = {};
  for (let i = 0; i < nums.length; ++i) {
    if (nums[i] in hit) {
      return [hit[nums[i]], i]
    }
    let hitValue = target - nums[i];
    hit[hitValue] = i;
  }
};
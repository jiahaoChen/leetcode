/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  let pZero = 0;
  let pValue = 0;
  while (pValue < nums.length) {
    while (pZero < nums.length && nums[pZero] != 0) {
      pZero++;
    }
    while(pValue < nums.length && (nums[pValue] == 0 || pValue < pZero)) {
      pValue++;
    }
    if (pValue >= nums.length || pZero >= nums.length)
      return;
    nums[pZero] = nums[pValue];
    nums[pValue] = 0;
    pZero++;
    pValue++;
  }
};
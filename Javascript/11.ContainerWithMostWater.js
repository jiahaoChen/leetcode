/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  var maxWater = 0;
  var left = 0;
  var right = height.length-1;
  while (left < right) {
    maxWater = Math.max(maxWater, Math.min(height[left], height[right]) * (right - left));
    if (height[left] > height[right]) {
      right--;
    } else {
      left++;
    }
  }
  return maxWater;
};
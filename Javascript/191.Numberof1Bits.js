/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  var ret;
    ret = (n & 0x55555555)
        + ((n >> 1) & 0x55555555);
    ret = (ret & 0x33333333)
        + ((ret >> 2) & 0x33333333);
    ret = (ret & 0x0F0F0F0F)
        + ((ret >> 4) & 0x0F0F0F0F);
    ret = (ret & 0x00FF00FF)
        + ((ret >> 8) & 0x00FF00FF);
    ret = (ret & 0x0000FFFF)
        + ((ret >> 16) & 0x0000FFFF);
    return ret;
};


/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  var sum = 0;
  while (n != 0) {
    sum++;
    n &= n-1;
  }
  return sum;
};
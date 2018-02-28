/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  if (s.length < 2) return s.length;
  var subHit = {};
  var max = 0;
  var startIndex = 0;
  var i = 0;
  for (; i < s.length; ++i) {
    if (s[i] in subHit && subHit[s[i]] >= startIndex ) {
      startIndex = subHit[s[i]]+1;
    }
    subHit[s[i]] = i;
    max = Math.max(max, i-startIndex+1);
  }
  return max;
};
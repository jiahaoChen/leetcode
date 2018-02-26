/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  var map = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
  }
  var preValue = 0;
  var ret = 0;
  for (let i = s.length-1; i >= 0; --i) {
    if (preValue > map[s[i]]) {
      ret -= map[s[i]];
    } else {
      ret += map[s[i]];
    }
    preValue = map[s[i]];
  }
  return ret;
};
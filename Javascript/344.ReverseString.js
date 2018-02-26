/**
 * @param {string} s
 * @return {string}
 */

var reverseString = function(s) {
  // let n = s.length
  // var ret = ""
  // for(let i = 0; i < n; ++i) {
  //   ret = ret.concat(s[n-1-i])
  // }
  // return ret
  return s.split('').reverse().join('');
};
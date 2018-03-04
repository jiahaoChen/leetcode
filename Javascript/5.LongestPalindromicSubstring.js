/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  function findByIndex(index, s) {
    var right = index+1;
    var left = index-1;
    while (right < s.length && s[right] == s[index])
      right++;
    while (left >= 0 && s[left] == s[index])
      left--;
    while(right < s.length && left >= 0) {
      if(s[right] != s[left]) {
        break;
      }
      right++;
      left--;
    }
    right--;
    left++;
    var ret = s.slice(left, right+1);
    // console.log(ret, left, right)
    return ret;
  }
  
  var ret = "";
  for (let i = 0; i < s.length; ++i) {
    let curr = findByIndex(i, s);
    ret = (ret.length > curr.length)? ret: curr;
    
  }
  return ret;
};
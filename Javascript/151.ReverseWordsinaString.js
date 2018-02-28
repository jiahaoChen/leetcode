/**
 * @param {string} str
 * @returns {string}
 */
var reverseWords = function(str) {
  str = str.replace(/\s+/g, ' ').trim();
  function reverse(s){
    return s.split("").reverse().join("");
  }
  return reverse(str).split(' ').map((s)=>reverse(s)).join(' ')
};
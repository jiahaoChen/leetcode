/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
  if (numRows < 2)
    return s;
  var retArr = []
  for (let i = 0; i < numRows; ++i) {
    retArr.push("")
  }
  let cur = 0;
  let direction = 1;
  for (let j = 0; j < s.length; ++j) {
    retArr[cur] = retArr[cur].concat(s[j])
    cur = cur + direction;
    if (cur == 0)
      direction = 1;
    if (cur == numRows-1)
      direction = -1;
  }
  return retArr.join('');
};
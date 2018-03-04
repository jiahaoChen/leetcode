/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
  var ret = 0;
  var currPathLength = 0;
  var levelLength = [0];
  var i = 0;
  var level = 0;
  var isFile = false;
  while (i < input.length) {
    if (input[i] == '\n') {
        levelLength[level+1] = currPathLength;
        level = 0;
        currPathLength = 0;
        i++;
        isFile = 0;
    } else if (input[i] == '\t') {
      level++;
      currPathLength = levelLength[level]+1;
      i++;
    } else if (input[i] == '.') {
      isFile = true;
      currPathLength++;
      i++;
    } else {
      currPathLength++;
      if (isFile)
        ret = Math.max(ret, currPathLength)
      i++;
    }
  }
  // console.log(levelLength)
  return ret;
};
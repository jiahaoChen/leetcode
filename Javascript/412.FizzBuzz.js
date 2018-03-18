/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
  var ret = [];
  for (let i = 1; i <= n; ++i) {
    if(!(i%15))
      ret.push('FizzBuzz');
    else if(!(i%3))
      ret.push('Fizz');
    else if(!(i%5))
      ret.push('Buzz');
    else
      ret.push(''+i)
  }
  return ret;
};
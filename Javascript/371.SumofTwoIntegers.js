/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function(a, b) {
  var ret = 0;
  var xorValue = 0;
  var andValue = 0;
  do {
    // console.log(`xorValue: ${xorValue}, andValue: ${andValue}`)
    xorValue = a^b;
    andValue = (a&b) << 1;
    a = xorValue;
    b = andValue;
  }while(andValue) 
    
  return xorValue;    
};
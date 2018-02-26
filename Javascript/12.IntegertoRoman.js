/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
  var oneMap = {
    '0': '',
    '1': 'I', 
    '2': 'II',
    '3': 'III',
    '4': 'IV',
    '5': 'V',
    '6': 'VI',
    '7': 'VII',
    '8': 'VIII',
    '9': 'IX'
  }
  var tenMap = {
    '0': '',
    '1': 'X', 
    '2': 'XX',
    '3': 'XXX',
    '4': 'XL',
    '5': 'L',
    '6': 'LX',
    '7': 'LXX',
    '8': 'LXXX',
    '9': 'XC'
  }
  var hundredMap = {
    '0': '',
    '1': 'C', 
    '2': 'CC',
    '3': 'CCC',
    '4': 'CD',
    '5': 'D',
    '6': 'DC',
    '7': 'DCC',
    '8': 'DCCC',
    '9': 'CM'
  }
  var thousandMap = {
    '0': '',
    '1': 'M', 
    '2': 'MM',
    '3': 'MMM',
  }
  
  if (num < 1 && num > 3999) 
    return null;
  
  return thousandMap[Math.floor(num/1000)] + 
    hundredMap[Math.floor((num%1000)/100)] + 
    tenMap[Math.floor((num%100)/10)] + 
    oneMap[(num%10)]
};
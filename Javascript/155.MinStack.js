/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.dataArr = [];
  this.minArr = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
  this.dataArr.push(x);
  
  if (this.minArr.length == 0 || x < this.dataArr[this.minArr[this.minArr.length-1]])
    this.minArr.push(this.minArr.length)
  else
    this.minArr.push(this.minArr[this.minArr.length-1])  
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
  this.dataArr.pop()
  this.minArr.pop()
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
  return this.dataArr[this.dataArr.length-1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
  return this.dataArr[this.minArr[this.minArr.length-1]]
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = Object.create(MinStack).createNew()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
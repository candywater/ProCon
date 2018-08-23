/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
  var res = parseInt(str);
  if(isNaN(res)) return parseInt(0);
  else if(res > 2147483647) return parseInt(2147483647);
  else if(res < -2147483648) return parseInt(-2147483648);
  else return res;
};

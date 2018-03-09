/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
  /*
  var i = Math.ceil(x/2);
  for(; i >= 0; i--){
    if(i*i <= x) return i;
  }
  return 1;
  */
  return Math.floor(Math.sqrt(x))
};

/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  var more = true;

  for(var i = digits.length - 1; i >= 0; i--){
    var plus = more ? 1 : 0;
    digits[i] = plus + digits[i]
    if(digits[i] >= 10) more = true;
    else more = false;
    digits[i] = digits[i] % 10
  }
  if(digits[0] == 0 && more){
    //console.log("sdf")
    var res = [parseInt(1)];
    res = res.concat(digits);
    return res;
  }
  else return digits;
};

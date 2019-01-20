/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
  let prime = 2;
  while(num % prime == 0 && num != 0) num = parseInt(num/prime);
  prime = 3;
  while(num % prime == 0 && num != 0) num = parseInt(num/prime);
  prime = 5;
  while(num % prime == 0 && num != 0) num = parseInt(num/prime);
  return num == 1 ;
};
console.log(isUgly(6));
console.log(isUgly(14));
console.log(isUgly(17));

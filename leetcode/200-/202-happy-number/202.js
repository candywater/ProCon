/**
 * @param {number} n
 * @return {boolean}
 */
 //follow https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
var isHappy = function(n) {
  let slow = calc (n);
  let fast = calc (slow);

  while(slow != fast){
    slow = calc (slow);
    fast = calc (fast);
    fast = calc (fast);
  }
  if(slow == 1) return true;
  else return false;
};

var calc = function (num){
  let res = 0;
  while(num > 0){
    res += (num%10) * (num%10);
    num = parseInt(num/10);
  }
  return res;
}

console.log(isHappy(19));

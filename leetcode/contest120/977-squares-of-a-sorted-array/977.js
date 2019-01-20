/**
 * @param {number[]} A
 * @return {number[]}
 */

var comp = function(a, b){
  return parseInt(a) - parseInt(b);
}
 
var sortedSquares = function(a) {
  var res = [];
  for(var i in a){
    res.push(a[i]*a[i])
  }
  return res.sort(comp);
};

console.log(sortedSquares([33,4,8]))
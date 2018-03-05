/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
  var more = false;

  var i = a.length - 1;
  var j = b.length - 1;
  var res = [];
  var index = 0;

  for(; i >= 0 || j >= 0; i--, j--, index++){
    var x = i < 0 ? parseInt(0) : a[i];
    var y = j < 0 ? parseInt(0) : b[j];
    res[index] = parseInt(x) + parseInt(y);
    res[index] = more ? res[index] + parseInt(1) : res[index];
    //console.log(x + " " + y + " " + res[index]);
    if(res[index] > 1) more = true;
    else more = false;
    res[index] = res[index] % 2;
  }
  if(more)
    res.push(parseInt(1));
  //console.log(res);
  return res.reverse().join("");
};

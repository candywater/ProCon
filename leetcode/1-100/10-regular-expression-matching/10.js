/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
  var  res = s.match(p);
  if(res == null) return false;
  else return res[0].length == s.length;
    
};

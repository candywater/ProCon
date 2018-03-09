/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
  if(s.match(/^\s*$/)) return 0;
  s = s.split(" ");
  //console.log(s)
  for(var i = s.length - 1; i >= 0; i--){
    if(s[i].length != 0) return s[i].length;
  }
  return 0;
};

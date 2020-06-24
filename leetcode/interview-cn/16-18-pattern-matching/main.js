/**
 * @param {string} pattern
 * @param {string} value
 * @return {boolean}
 */

var isSingle = false;

// all search
var patternMatching = function(pattern, val) {
  // special case
  if(pattern.length == 0 && val.length == 0) return true;
  if(pattern.length == 0) return false;
  isSingle = isSinglePattern(pattern)
  if(isSingle && val.length == 0) return true;

  var first = "";
  if(pattern.length > 0)
    first = pattern[0];

  for(var i = 0; i <= val.length; i++){
    var a = val.substring(0, i);
    if(isMatchA(pattern, val, a, first)) 
      return true;
  }
  return false;
};

// start from A
function isMatchA(pattern, val, a, first = "a"){
  var res = "";
  for(var i = 0; i < pattern.length; i++){
    // cut edge
    if(res.length > val.length) 
      return false;
    if(pattern[i] == first){
      res += a;
      continue;
    }
    for(var j = res.length; j <= val.length; j++){
      // set b, from the end of a
      var b = val.substring(res.length, j);
      //console.log(`res:[${res}] `)
      if(isMatchB(pattern, val, a, b, first, res, i)) 
        return true;
    }
    break;
  }
  // only "a" exist
  if(res == val && isSingle)  return true;
  return false;
}

function isMatchB(pattern, val, a, b, first, res, index){
  if(a == b) return false;
  for(var i = index; i < pattern.length; i++){
    // cut edge
    if(res.length > val.length) 
      return false;
    if(pattern[i] == first)
      res += a;
    else
      res += b;
  }
  //console.log(`res:[${res}] index:[${index}] a:${a} b:${b}`)
  if(res == val) return true;
  return false;
}

function isSinglePattern(p){
  var a = 0, b = 0;
  for(var i = 0; i < p.length; i++){
    if(p[i] == "a") a++
    else b++
  }
  return a == 0 || b == 0;
}

function debug(a, b){
  if(a == b) 
    console.log(`CORRECT!! `)
  else
    console.log(` WRONG!! `)
}

//patternMatching("abba", "dogcatcatdog")
debug(patternMatching("abba", "dogcatcatdog"), true);
debug(patternMatching("abba", "dogcatcatfish"), false);
debug(patternMatching("aaaa", "dogcatcatdog"), false);
debug(patternMatching("abba", "dogdogdogdog"), true);
debug(patternMatching("a", ""), true);
debug(patternMatching("ab", ""), false);
debug(patternMatching("bbbbbbbbabbbbbbbbbbbabbbbbbba", "zezezezezezezezezkxzezezezezezezezezezezezkxzezezezezezezezkx"), true);
debug(patternMatching("bbaba",
"ajocitdfyhohchqvilvdjjocitdfyhohchqvilvdj"), false);
debug(patternMatching("", ""), true);
debug(patternMatching("bbb","xxxxxx"), true);
debug(patternMatching("abbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbabbbb", "yxankynynxnxnxxyxyyyxxakxanaxnankyykxxannxayyyaxakyyyxxyxyyxxkxyyyyxnxxyykayyanayxayknayxyyynyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyykxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyyxankynynxnxnxxyxyyyxxakxanaxnankyykxxannxayyyaxakyyyxxyxyyxxkxyyyyxnxxyykayyanayxayknayxyyynyxxykykyyxxykykyyxxxykykyy"), false);


//patternMatching("abab", "abcdefg")















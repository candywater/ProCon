/**
 * @param {string} pattern
 * @param {string} value
 * @return {boolean}
 */

var isSingle = false;

var patternMatching = function(pattern, v) {
  // special case
  if(pattern.length == 0 && v.length == 0) return true;
  if(pattern.length == 0) return false;
  isSingle = isSinglePattern(pattern)
  if(isSingle && v.length == 0) return true;

  var first = "";
  if(pattern.length > 0)
    first = pattern[0];

  for(var i = 0; i <= v.length; i++){
    var a = v.substring(0, i);
    if(isMatchA(pattern, v, a, first)) return true;
  }
  return false;
};

// start from A
function isMatchA(pattern, val, a, first = "a"){
  var res = "";
  //console.log(`a:[${a}]  `)
  for(var i = 0; i < pattern.length; i++){
    if(res.length > val.length) return false;
    if(pattern[i] == first){
      res += a;
      continue;
    }
    for(var j = res.length; j <= val.length; j++){
      var b = val.substring(res.length, j);
      //console.log(`a:[${a}]  b:[${b}]`)
      if(isMatchB(pattern, val, a, b, i, first)) return true
    }
  }
  // only "a" exist
  if(res == val && isSingle)  return true;
  return false;
}

function isMatchB(pattern, val, a, b, index, first){
  var res = "";
  //console.log(`res before: [${res}]`)
  if(a == b) return false;
  for(var i = 0; i < pattern.length; i++){
    if(res.length > val.length) return false;
    if(pattern[i] == first)
      res += a;
    else
      res += b;
  }
  //console.log(`res after: [${res}] a:[${a}]  b:[${b}] `)
  //console.log(`a:[${a}]  b:[${b}] index:[${index}] res: [${res}]`)
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
debug(patternMatching("", ""), true);
debug(patternMatching("bbb","xxxxxx"), true);
debug(patternMatching("abbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbabbbb",
"yxankynynxnxnxxyxyyyxxakxanaxnankyykxxannxayyyaxakyyyxxyxyyxxkxyyyyxnxxyykayyanayxayknayxyyynyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyykxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyxxykykyyyxankynynxnxnxxyxyyyxxakxanaxnankyykxxannxayyyaxakyyyxxyxyyxxkxyyyyxnxxyykayyanayxayknayxyyynyxxykykyyxxykykyyxxxykykyy"), false);


//patternMatching("abab", "abcdefg")















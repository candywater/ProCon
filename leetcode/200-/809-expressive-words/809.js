/**
 * @param {string} S
 * @param {string[]} words
 * @return {number}
 */
var expressiveWords = function(S, words) {
  // a question : can "ll" be extented as "lll" ? assume yes
  // accepted , so answer is yes
  let table = recognizeword(S);
  //console.log(table);
  let count = 0;
  for(let word of words){
    let tmptable = recognizeword(word);
    //console.log(tmptable);
    if(comp(table, tmptable)) count++;
  }
  return count;
};

var comp = function (table, tmptable){
  if(table.length != tmptable.length) return false;
  for(let i = 0; i < table.length; i++){
    if(table[i][0] != tmptable[i][0]) return false;
    if(table[i][1] < 3 && table[i][1] != tmptable[i][1]) return false;
    if(table[i][1] < tmptable[i][1]) return false;
  }
  return true;
}

var recognizeword = function (word){
  let tmp;
  let res = [];
  if(word.length > 0) tmp = word[0];
  let j = 0;
  for(let i = 1; i < word.length; i++){
    if(tmp != word[i]) {
      res.push([tmp, i-j])
      tmp = word[i];
      j = i;
    }
  }
  res.push([tmp, word.length-j])
  return res;
}
//console.log(expressiveWords("heeellooo",["hello", "hi", "helo"]));
console.log(expressiveWords("heeelllooo",["hello", "hi", "hello"]));

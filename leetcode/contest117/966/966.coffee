###
 * @param {string[]} wordlist
 * @param {string[]} queries
 * @return {string[]}
###
spellchecker = (wordlist, queries)->
  dict = new Map();
  res =[]
  for i in wordlist
    low = i.toLowerCase();
    low = low.replace(/[aeiou]/g,"a")
    # low = low.split("").sort().join("");
    if not dict.has(low)
      insidedict = new Set();
      insidedict.add(i)
      dict.set(low, insidedict);
    else  
      dict.get(low).add(i)

  for i in queries
    low = i.toLowerCase();
    key = low.replace(/[aeiou]/g, "a")
    # low = low.split("").sort().join("");
    if dict.has(key)
      if dict.get(key).has(i)
        res.push(i)
      else
        flg = true
        entries = dict.get(key).entries()
        for j from entries
          tmp = j[0].toLowerCase();
          if tmp is low
            res.push(j[0])
            flg = false
            break;
        res.push(dict.get(key).entries().next().value[0]) if flg
    else  
      res.push("")
      
  # console.log dict
  return res
      

w= ["KiTe","kite","hare","Hare"]
q= ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]

# console.log spellchecker(w, q)

w = ["zuo", "zeo"]
q = ["zEo"]
console.log spellchecker(w, q)


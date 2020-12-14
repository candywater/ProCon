
var n = 4
var w = [2, 1, 3, 2]
var v = [3, 2, 4, 2]
var A = 5

var ans = 0

AllSearch();

function AllSearch(){
  var boollist = []
  for(var i = 0; i < w.length; i++)
    boollist.push(false)
  rec(boollist, 0)

  console.log(ans)
}

function rec(boollist, i){
  if(i >= boollist.length){
    //console.log(boollist)
    var weight = 0
    var value = 0
    for(var i = 0; i < boollist.length; i++){
      if(boollist[i]){
        weight += w[i];
        value += v[i];
      }
    }
    if(weight > A)
      return
    if(value > ans)
      ans = value
    return 
  }

  boollist[i] = false;
  rec(boollist, i+1)
  boollist[i] = true;
  rec(boollist, i+1)
}
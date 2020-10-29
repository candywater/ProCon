
var n = 4
var w = [2, 1, 3, 2]
var v = [3, 2, 4, 2]
var A = 5

// bottom - up
function knapsack(){
  var table = [];
  var table_len = 0;
  for(var i = 0; i < w.length; i++){
    table_len += w[i];
  }
  // memset
  for(var i = 0; i <= table_len; i++){
    table.push(0);
  }

  console.log(table)
  // dp 
  for(var i = 0; i < w.length; i++){
    if(table[w[i]] < v[i])
      table[w[i]] = v[i]
    for(var j = i + 1; j < w.length; j++){
      if(table[w[i]] + v[j] > table[w[i] + w[j]])
        table[w[i] + w[j]] = table[w[i]] + v[j]
    }
  }
  // for (var i = 0; i < w.length; i++) {
  //   for (var k = 1; k < table.length; k++) {
  //     if(k-w[i] >= 0 
  //       && table[k] < table[k-w[i]] + v[i]){

  //       table[k] = table[k-w[i]] + v[i]
  //       console.log(`table[k]: ${table[k]}, i: ${i}, table[k-w[i]] + v[i]: ${table[k-w[i]] + v[i]}`)
  //     }
  //     else {
  //       if(table[k] < table[k-1])
  //         table[k] = table[k-1];
  //     }
  //     console.log(table)
  //   }
  // }

  console.log(table)
  console.log(table[A])
}

knapsack();
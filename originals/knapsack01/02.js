
var n = 4
var w = [2, 1, 3, 2]
var v = [3, 2, 4, 2]
var targetW = 5

function knapsack_multi(){
  var dp = [];
  var maxWeight = 0;
  // get max weight
  for(var i = 0; i < w.length; i++){ 
    maxWeight += w[i]; 
  }
  // memset
  for(var i = 0; i <= w.length; i++){
    dp.push([]);
    for(var j = 0; j <= maxWeight; j++){ 
      dp[i].push(0); 
    }
  }

  // dp 
  // top - down
  showlist(dp)

  for (var i = w.length-1; i >= 0; i--) {
    for (var j = maxWeight-1; j >= 0; j--) {
      if (j - w[i] < 0)
        dp[i][j] = dp[i + 1][j];
      else
        dp[i][j] = max(dp[i + 1][j], dp[i+1][j - w[i]] + v[i]);
    }
    showlist(dp)
  }

  console.log(dp[0][targetW])

}


function max(a, b) {
  return a > b ? a : b;
}

function showlist(dp) {
  for (var i of dp) {
    var str = "["
    for (var j of dp)
      str += j + ", "
    str += "]"
    console.log(str)
  }
  console.log();
}

knapsack_multi();
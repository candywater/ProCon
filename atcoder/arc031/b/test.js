const {exec} = require("child_process");
const fs = require("fs")

var list = []
var count = 0;

for(var i = 0; i < 10; i++){
  list.push([]);
  for(var j = 0; j < 10; j++){
    list[i].push(parseInt(j));
  }
}
console.log(list);


var random_a_list = ()=>{
  var string = ""
  for(var i = 0; i < 10; i++){
    for(var j = 0; j < 10; j++){
      var t = parseInt(Math.random()*10);
      t = t % 2 == 0;
      list[i][j] = t == 0 ? 'x' : 'o';
      string += list[i][j]
    }
    string += "\n"
  }

  fs.writeFile("./_test", string, (err) => {})
  runright();
}


var runright = ()=>{
  var rightans = "";
  exec("./_r < ./_test", (err, stdout, stderr) => {
    rightans = stdout;
    runwrong(rightans);
})}

var runwrong = (right)=>{
  var wrong = ""
  exec("./_w < ./_test", (err, stdout, stderr) =>{
    wrong = stdout;
    comp(right, wrong);
})}

var comp= (right, wrong)=>{
  //console.log(right.trim())
  //console.log(wrong.trim())
  if(wrong != right){
    console.log(list)
    console.log("count:"+count)
    return;
  }
  else{
    ++count;
    random_a_list();
  }
}

random_a_list();


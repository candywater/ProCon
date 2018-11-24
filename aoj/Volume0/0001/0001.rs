use std::io;
fn main(){
  //let mut a = String::new();
  let mut b = String::new();
  
  io::stdin().read_line(&mut b).expect("fail");
  print!("{}", b);
}
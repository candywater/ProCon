#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> 
void show(T a){
  for(auto i : a){ cout << i << " "; }
  cout << endl;
}
bool isOdd(int a){
  return a%2 == 1;
}
bool isEven(int a){
  return a%2 == 0;
}
int f(int a){
  if(isOdd(a))
    return 3*a+1;
  else
    return a/2;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int s;
  cin >> s;
  unordered_set<int> map;
  
  int count = 1;
  int n = s;
  do{
    map.insert(n);
    n = f(n);
    //cout << "n:" << n << endl;
    count++;
  }while(map.count(n) <= 0);
  
  //show(map);
  
  cout << count << endl;
}

//the java file I wrote is a disaster. 
// so I rewrite it in cpp

#include <iostream>
#include <unordered_map>

using namespace std;


template<typename T> void show(T a){
  for(auto i : a){}
  cout << endl;
}

int main(int argc, char *argv[]){
  int n, m;
  char t1, t2;
  cin >> n;
  while(n != 0){
    unordered_map<char, char> nummap;
    for(int i = 0; i < n; i++){
      cin >> t1 >> t2;
      nummap.insert({t1, t2});
    }
    cin >> m;
    for(int i = 0; i < m ; i++){
      cin >> t1;
      if(nummap.count(t1) != 0)
        cout << nummap[t1];
      else
        cout << t1;
    }
    cout << endl;
    cin >> n;
  }
  return 0;
}




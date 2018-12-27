#include "iostream"
#include "vector"

using namespace std;

int main(int argc, char const *argv[]) {

  vector<vector<int> > a(2, vector<int>());
  vector<int> t1, t2;
  int n;
  int tmp;

  t1.push_back(0);
  t2.push_back(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    a[0].push_back(tmp);
    int back = t1.back();
    t1.push_back(tmp + back);
  }
  for(int i = 0; i < n; i++){
    cin >> tmp;
    a[1].push_back(tmp);
    int back = t2.back();
    t2.push_back(tmp + back);
  }


  /*for(int i = 0; i < n; i++){
    cout << t1[i+1] << " ";
  } cout << endl;
  for(int i = 0; i < n; i++){
    cout << t2[i+1] << " ";
  } cout << endl;*/

  int res = t1.front() + t2.back();
  for(int i = 1; i <= n; i++){
    //int amount1 = t1.back() - t1[i];
    int amount2 = t2.back() - t2[i - 1];
    if(t1[i] + amount2 > res){
        res = t1[i] + amount2;
    }
  }

  cout << res << endl;


  /* code */
  return 0;
}

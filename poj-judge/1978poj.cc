/*c++11*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

static int n,r;
static vector<int> cards;

void solute();

int main(int args, char *argc[]){

  while(cin>>n>>r,n&&r){
    solute();
  }
  return 0;
}

void solute(){
  cards.clear();
  cards.resize(n);
  for(int i=0;i<n;i++)
    cards[i]=n-i;

  vector<int> stack;

  int p,c;
  for(int i=0;i<r;i++){
    cin>>p>>c;
    stack.assign(cards.begin()+p-1,cards.begin()+p+c-1);
    cards.erase(cards.begin()+p-1,cards.begin()+p+c-1);
    cards.insert(cards.begin(),stack.begin(),stack.end());
  }
  assert (cards.size() == n);
  cout<<cards[0]<<endl;
}

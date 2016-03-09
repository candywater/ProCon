#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

int main(int args, char *argc[]){
  bitset<30> students;
  int a;
  while(cin>>a)
    students[a-1]=1;
  for(int i=0;i<30;i++)
    if(students[i]==0)
      cout<<i+1<<endl;
  return 0;
}

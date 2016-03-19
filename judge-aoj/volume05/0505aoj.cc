/*c++98*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main(int args, char *argc[]){
  int student,locations;
  //ifstream ifs("input.txt");
  while(cin>>student>>locations, student&&locations){
    int wishes[locations];

    for(int i=0;i<locations;i++)
      wishes[i]=0;//,printf("wishes[%d]:%d ",i,wishes[i]);printf("\n");
    int stu=student;
    while(stu--){
      int loc=locations;
      while(loc--){
        int tmp;cin>>tmp;
        wishes[locations-loc-1]+=tmp;
      }
    }

    /*for(int i=0;i<locations;i++)
      printf("wishes[%d]:%d ",i,wishes[i]);printf("\n");*/

    map<double,int> res;
    int loc=locations;
    while(loc--){
      res.insert(make_pair((double)wishes[loc]-(double)loc/100,loc));
    }

    for(map<double,int>::iterator iz=(--res.end());
    iz!=res.begin();iz--)
      //cout<<"("<<(iz->first)<<")",
      cout<<(iz->second)+1<<" ";
    cout<<(res.begin())->second+1<<"\n";
  }
  return 0;
}

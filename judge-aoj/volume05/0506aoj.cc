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

string solve(string s){
  int count=0;
  string res;
  //new char
  res.push_back(s[0]);
  count++;
  for(int i=1;i<s.size();i++){
    //the same char 
    if(*res.rbegin()==s[i])
        count++;
    //not the same
    else {
      char a=*res.rbegin();
      res.resize(res.size()-1);
      res.append(to_string(count));
      res.push_back(a);
      count=1;
      res.push_back(s[i]);
    }
//    printf("[%c]",s[i]);
  }
  char a=*res.rbegin();
  res.resize(res.size()-1);
  res.append(to_string(count));
  res.push_back(a);
  return res;
}

/*
//20*(100+100*2^20)/2=10*(100+100*1024*1024)=1000+10^9<=c10^9
string solve(string s){
int count=0;
string res;
//new char
res.push_back(s[0]);
count++;
for(int i=1;i<s.size();i++){
//the same char 
if(*res.rbegin()==s[i])
count++;
//not the same
else {
char a=*res.rbegin();
res.erase(res.size()-1);
res.push_back(count+'0');
res.push_back(a);
count=1;
res.push_back(s[i]);
}
}

if(count==0)
count++;
char a=*res.rbegin();
res.erase(res.size()-1);
res.push_back(count+'0');
res.push_back(a);
return res;
}
 */
//num<=20, str.size()<=100
int main(int args, char *argc[]){
  int num;
  while(cin>>num,num){
    string s;
    cin>>s;

    string res;
    res=s;
    for(int i=0;i<num;i++){
      res=solve(res);
 //     cout<<res<<endl;
    }
    cout<<res<<endl;
  }
  return 0;
}

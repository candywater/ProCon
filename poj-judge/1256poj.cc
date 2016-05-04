/*c++11*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <bitset>
#include <cmath>
#include <utility>

using namespace std;

//static set<string> ans;
static string repeat="\0";
//static set< bitset<60> > table;//table[ix][iy], ix=pos, iy=str[i]
//static map<char,int> label;//label.find(a)=const num;

int strCompare(string, string);

void backtrack(string str,string res, bitset<15> mark, int pos){
  if(strCompare(repeat,res) > 0) return;
  if(res.length()==str.length()){
    repeat=res;
    cout<<res<<endl;
  }
  for(int i=0;i<str.length();i++){
    if(mark[i]==true)
      continue;
    res+=str[i];
    mark[i]=true;
    backtrack(str,res,mark,pos+1);
    res.erase(res.end()-1);
    mark[i]=false;
  }
  return;
}
int compare(char str1, char str2){
  char a=str1;
  char b=str2;
  if(a>='a' && a<='z') a+='A'-'a';
  if(b>='a' && b<='z') b+='A'-'a';

  if(a==b){
    if(str1==str2)
      return 0;
    else 
      return str1-str2;
  }
  else
    return a-b;
}

int strCompare(string str1, string str2){
  int pos=0;
  while(pos!=str1.length()){
    int tmp=compare(str1[pos], str2[pos]);
    if(tmp!=0)
      return tmp;
    pos++;
  }
  return 0;
}


void solute(string str){
  bitset<15> mark(0);
  string res;
  backtrack(str,res,mark,0);
}

int main(int args, char *argc[]){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string str;
    cin>>str;
    repeat="\0";
    //cout<<"n:"<<n<<" str:"<<str<<endl;
    //table.clear();

    for(int ix=str.length();ix!=0;ix--)
      for(int iy=1;iy!=ix;iy++)
        if(compare(str[iy-1],str[iy]) > 0)
          swap(str[iy-1],str[iy]);
    solute(str);
  }
  return 0;
}
/*bitset<60> tmp;
  for(int ix=0;ix<str.length();ix++){
  tmp=tmp<<4;
  tmp&=label[res[ix]];
  }
  if(table.count(tmp)==0){
  table.insert(tmp);
  cout<<res<<endl;
  }*/

/*
   for(int ix=0;ix<str.length();ix++)
   label.insert(make_pair(str[ix],ix));
 */

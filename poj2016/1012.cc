#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;


/*2,7,5,30,169,441,1872,
 7632,1740,93313,459901,
 1358657,2504881,13482720*/
int table[13]={0};

void test(int k){
  int good;
  int bad;
  int index;
  int result=1;
  bool flag=true;

  for(;;result++){
    index=0;
    good=k;
    bad=k;
    index=(index+result)%(good+bad);
/*    cout<<"\nres:"<<result//<<"good:"<<good<<" bad:"<<bad
      <<" i:"
      <<index<<" ";*/
    while(true){
      if(bad==0)
        break;
      //cout<<"index:"<<index<<" ";
      //if kill good guy
      if(index<k){
        flag=false;
        break;
      }
      bad--;
/*      if(index!=(good+bad-1)) 
        index=(index+1)%(good+bad+1);*/
      
      index=(index+result)%(good+bad);
    }
    if(flag){
      table[k-1]=result+1;
      //cout << "good:"<<good<<" bad:"<<bad<<" ";
      //cout<<"table["<<k-1<<"]:"<<table[k-1]<<endl;
      return;
    }
    flag=true; 
  }
}
int main(int args, char *argc[]){
  int k;

  for(int i=0;i<14;i++)
    test(i+1);

  while(cin >> k){
    if (k==0) return 0;
    cout<<table[k-1]<<endl;
  }
  return 0;
}


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
#include <deque>

using namespace std;

int main(int args, char *argc[]){
  char a,b,c;
  char t;
  int joi=0;
  int ioi=0;
  deque<char> que;

  while(scanf("%c",&a)!=EOF){
    scanf("%c%c",&b,&c);
    que.clear();
    joi=0;
    ioi=0;
    if(a=='J' && b=='O' && c=='I')
      joi++;
    else if(a=='I' && b=='O' && c=='I')
      ioi++;

    que.push_back(a); 
    que.push_back(b); 
    que.push_back(c); 

    while(scanf("%c",&t)!=EOF){
      if(t=='\n')
        break;
      que.pop_front();
      que.push_back(t);

      if(que[0]=='J' && que[1]=='O' && que[2]=='I')
        joi++;
      else if(que[0]=='I' && que[1]=='O' && que[2]=='I')
        ioi++;
    }
    printf("%d\n%d\n",joi,ioi);
  }
  return 0;
}

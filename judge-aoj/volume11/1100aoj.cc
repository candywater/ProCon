#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>

#define PI 3.14159265359

using namespace std;

double line(int x1,int x2,int y1,int y2){
  //return length of line
  return sqrt(
      pow((double)x1-(double)x2,2.0)+
      pow((double)y1-(double)y2,2.0));
}
//reference:http://imagingsolution.net/math/calc_n_point_area/
//reference:http://d.hatena.ne.jp/nanikaka/20111016/1318734562
int main(int args, char *argc[]){
  int n;
  int count=0;
  //INPUT
  while(cin >> n){
    count++;
    double sum=0;

    if (n==0)
      return 0;
    int x[n],y[n];
    for(int i=0;i<n;i++){
      cin>>x[i]>>y[i];
    }

    for(int i=0;i<n;i++)
      sum+=((double)x[i]*(double)y[(i+1)%n]-(double)x[(i+1)%n]*(double)y[i])/2;

    printf("%d %.1f\n",count,-sum);
  }
  return 0;
}


/*
//cosA=(b^2+c^2-a^2)/2bc
//sinA=cos(90-A)
//a(1,2),b(0,1),c(0,2)
double a=line(x[1],x[2],y[1],y[2]);
double b=line(x[0],x[1],y[0],y[1]);
double c=line(x[0],x[2],y[0],y[2]);
double alpha=acos((b*b+c*c-a*a)/(2*b*c));
//area=bcsin(Theta)
sum+=(sin(alpha))*b*c/2;
printf("a:%f,b:%f,c:%f,cos(alpha):%f,sin(alpha):%f,alpha:%f,sum:%f\n",
a,b,c,(b*b+c*c-a*a)/2/b/c,sin(alpha),alpha,sum);

for(int i=3;i<n;i++){
//a(i-1,i),b(0,i-1),c(0,i)
a=line(x[i],x[i-1],y[i],y[i-1]);
b=line(x[0],x[i-1],y[0],y[i-1]);
c=line(x[0],x[i],y[0],y[i]);
alpha=acos((b*b+c*c-a*a)/(2*b*c));
sum+=sin(alpha)*b*c/2;
printf("a:%f,b:%f,c:%f,alpha:%f,sum:%f\n",
a,b,c,alpha,sum);
}
printf("%d %.1f\n",count,sum);
}
return 0;
}
 */


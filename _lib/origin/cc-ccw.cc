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

using namespace std;

class Point{
  public:
    int x,y;
    Point(int x,int y){
      this->x=x;
      this->y=y;
    }

    Point operator +(Point a){
      return Point(this->x+a.x, this->y+a.y);
    }
    Point operator -(Point a){
      return Point(this->x+a.x, this->y+a.y);
    }
    Point& operator +=(Point a){
      this->x+=a.x;
      this->y+=a.y;
      return *this;
    }
    Point& operator -=(Point a){
      this->x-=a.x;
      this->y-=a.y;
      return *this;
    }

};

int corss(Point, Point);
int dot(Point, Point);
int ccw(Point, Point, Point);

int cross(Point a, Point b){
  return (a.x*b.y - a.y*b.x);
}

int dot(Point a, Point b){
  return a.x*b.x+a.y*b.y;
}

//counterclockwise
int ccw(Point a, Point b, Point c){
  return cross(b-a,c-a);
}

int main(int args, char *argc[]){
  return 0;
}

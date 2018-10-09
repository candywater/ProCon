#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double M_PI0=3.141593;

/*
    delta=50平方単位増加後の半径の増加した量
    length=もとの半径の長さ
    M_PI*(length+delta)*(length+delta)/2-M_PI*length*length/2=50
    delta=-length+sqrt((100+M_PI*length*length)/M_PI)
 */
int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int years=0;
        double x,y;
        cin >> x >> y;
        double delta;
        double length=0;
        double distance=sqrt(x*x+y*y);
        //cout << "distance:" << distance <<endl ;
        while(length<distance){
            years += 1;
            delta=-length+sqrt((100+M_PI0*length*length)/M_PI0);
            length += delta;
            //cout << "delta:" << delta <<endl;
            //cout << "length:" <<length << endl;
        }
        cout << "Property " << i+1 ;
        cout <<": This property will begin eroding in year " ;
        cout << years << "."<<endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}

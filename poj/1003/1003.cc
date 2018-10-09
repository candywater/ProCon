#include <iostream>
#include <stdio.h>

using namespace std;
int main(void){
    double n;
    int m=2;
    n=2;
    while(true){
        cin >> n;
        //cout << n << endl;
        if(n==0.00){
            break;
        }
        double count=0;
        double length=0;
        while(length < n){
            //cout << "count:" << count <<endl;
            length=length+1/(count+2);
            //cout << 1/(count+2)<< endl;
            //cout << "length:" << length << endl;
            count++;
        }
        int number = count;
        cout << number << " card(s)" << endl;
    }
    return 0;
}

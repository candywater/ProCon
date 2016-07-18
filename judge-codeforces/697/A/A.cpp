#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

int main(){
	
	int t,s,x;
	//cout << INT_MAX <<endl;
	cin >> t >> s >> x;
	int a = x - 1;
	a -= t;
	x -= t;

	if(x % s == 0 && x / s >= 0)
		cout << "YES" << endl;
	else if(a % s == 0 && a / s > 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

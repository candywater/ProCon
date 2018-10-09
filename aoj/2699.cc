#include <stdio.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

double solve(int d, int e){
	//x + y = d
	//sqrt(x**x + y**y) = e
	int tmpx = 0, tmpy = 0;
	double res = 100000.0;
	for(int ix = 0;ix <= 100;ix++)
		for (int iy = 0;iy <= 100 ; iy++){
			if(ix + iy != d)
				continue;
			double tmp = sqrt(ix*ix + iy*iy) - (double)e;
			tmp = tmp>0?tmp:-tmp;
			if (tmp < res)
				res = tmp;
		}
	return res;
}

int main(){

	int d,e;
	while(cin >> d >> e , d||e){
		printf("%.10lf\n", solve(d, e));
	}

	return 0;
}

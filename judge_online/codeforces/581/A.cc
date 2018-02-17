#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	int red, blue;
	cin >> red >> blue;

	if(red < blue){
		int tmp = red;
		red = blue;
		blue = tmp;
	}

	//red is larger than blue
	int res = red - red + blue;
	cout << res << " ";
	res = (red - blue) / 2;
	cout << res << endl;

	return 0;
}
		

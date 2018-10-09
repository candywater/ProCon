#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int whoseTurn(char tmp){
	if(tmp == 'a')
		return 0;
	else if(tmp == 'b')
		return 1;
	else if(tmp == 'c')
		return 2;
	else 
		return -1;
}

int main(){
	string a,b,c;
	int ia,ib,ic;
	ia = 0;
	ib = 0;
	ic = 0;
	int turn = 0;//0,1,2  a,b,c

	cin >> a >> b >> c;
	
	turn = whoseTurn(a[ia++]);
	
	while(true){

		if(turn == 0){
			if(ia == a.length())
				break;
			turn = whoseTurn(a[ia++]);
		}
		else if(turn == 1){
			if(ib == b.length())
				break;
			turn = whoseTurn(b[ib++]);
		}
		else if(turn == 2){
			if(ic == c.length())
				break;
			turn = whoseTurn(c[ic++]);
		}
	}

	if(turn == 0)
		cout << "A" << endl;
	else if(turn == 1)
		cout << "B" << endl;
	else if(turn == 2)
		cout << "C" << endl;

	return 0;
}

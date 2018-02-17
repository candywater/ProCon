#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){

	deque<int> a;
	char b;
	while(cin >> b){
		a.push_back(b - '0');
		cout << b;
	}
	while(!a.empty()){
		cout << a.back();
		a.pop_back();
	}
	cout << endl;
	return 0;
}

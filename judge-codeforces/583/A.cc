#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
	int h[51] = {0};
	int w[51] = {0};
	set<int> a;

	int n;
	cin >> n;
	for(int i = 0;i < n*n; i++){
		int ta,tb;
		cin >> ta >> tb;
		if(h[ta] == 0 && w[tb] == 0){
			h[ta] = 1;
			w[tb] = 1;
			a.insert(i+1);
		}
	}
	for(auto ix = a.begin(); ix != a.end(); ix++){
		cout << *ix << " ";
	}
	cout << endl;
	return 0;
}

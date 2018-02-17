#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	long long int n;
	cin >> n;
	vector<long long int> a(n, 0);
	vector<long long int> b(n, 0);
	long long int tmp;
	long long int max = 0;

	for(auto ia = a.begin(); ia != a.end(); ia++ ){
		cin >> tmp;
		*ia = tmp;
	}
	
	b[n-1] = 0;
	for(long long int i = n-2; i >= 0; i--){
		if(a[i+1] > max) max = a[i+1];
		b[i] = max;
	}
	for(long long int i = 0; i < n;i++ ){
		if(b[i] >= a[i])
			cout << b[i] - a[i] + 1 << " ";
		else
			cout << "0 ";
	}
	cout << endl;
	return 0;
}

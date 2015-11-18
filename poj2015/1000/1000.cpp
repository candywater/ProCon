#include <iostream>
int main (void){
	int a,b;
	//std::cout << "a:";	
	std::cin >> a;
	//std::cout << "b:";
	std::cin >> b; 
	if(a<0 || b>10)
		std::cout << "error" << std::endl;
	std::cout << a+b <<std::endl;
	return 0;
}


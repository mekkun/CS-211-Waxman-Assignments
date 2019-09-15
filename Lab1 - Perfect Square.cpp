//Write a program to find and print the first perfect square (i*i)
//whose last two digits are both odd.

#include <iostream>
using namespace std;

int main(){
	for(int i = 1; i < 100; i++){     //squaring loop
		
		int square = i*i;
		
		if( (square%2 != 0) && ( (square/10)%2 !=0 ) ){    //last 2 digit odd test
			cout << square << endl;
			return 0;
		}
	}
	return 0; //no solution
}
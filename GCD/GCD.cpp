#include <iostream>


long long GCD(long long lNumber1, long long lNumber2) {
	//GCD of two numbers is a number, which divides both the numbers Number1 and Number2
	//This simple alogrithm we start a infinite loop wit number starting from 2
	//and we start dividing both the numbers number1 and number2 by the number. 
	//If both are completely divisible then we break out of the loop otherwise we continue

	long long lGCD = 2;
	for ( long long lGCD = 2 ; lGCD < lNumber1 + lNumber2; ++lGCD ) {
		if (lNumber1 % lGCD == 0 && lNumber2 % lGCD == 0)
			break;
	}

	return lGCD;
}

int main(int nArgv, char** pArgc) {
	//enter the two numbers
	long long lNumber1(0), lNumber2(0);
	std::cin >> lNumber1;
	std::cin >> lNumber2;

	std::cout << GCD(lNumber1, lNumber2);
	return 0;
}
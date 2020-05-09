#include <iostream>


long long GCD(long long lNumber1, long long lNumber2) {
	//GCD of two numbers is a number, which divides both the numbers Number1 and Number2
	//We will the Euclid algorithm to find the answer
	//wherein if a' is the remainder when number1 is dividied by number2
	//then d is the GCD if d divides a' as well as b
	if (lNumber2 == 0)
		return lNumber1;

	long long nNumberPrime = lNumber1 % lNumber2;
	return GCD(lNumber2, nNumberPrime );
}

//int main(int nArgv, char** pArgc) {
//	//enter the two numbers
//	long long lNumber1(0), lNumber2(0);
//	std::cin >> lNumber1;
//	std::cin >> lNumber2;
//	
//	if (lNumber1 > lNumber2) {
//		std::cout << GCD(lNumber1, lNumber2);
//	}
//	else 
//		std::cout << GCD( lNumber2, lNumber1 );
//
//	return 0;
//}

int gcd_naive(int a, int b) {
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << GCD(a, b) << std::endl;
	return 0;
}

#include <iostream>

long long LCMNaive(long long nN1, long long nN2) {
	for (long long i = 1; i <= static_cast<long long>(nN1 * nN2); ++i) {
		if (i % nN1 == 0 && i %nN2 == 0)
			return i;
	}

	return static_cast<long long>(nN1 * nN2);
}

long long GCDFast(long long nN1, long long nN2) {
	//GCD of two numbers is a number, which divides both the numbers Number1 and Number2
	//We will the Euclid algorithm to find the answer
	//wherein if a' is the remainder when number1 is dividied by number2
	//then d is the GCD if d divides a' as well as b

	if (nN2 == 0)
		return nN1;

	long long lNumberPrime = 0;
	if (nN2 <= nN1) {
		lNumberPrime = nN1 % nN2;
	}
	else {
		lNumberPrime = nN2 % nN1;
	}

	return GCDFast(nN2 <= nN1 ? nN2 : nN1, lNumberPrime);
}

long long LCMFast(long long nN1, long long nN2) {
	//optimal way to find LCM  is LCM(a,b) = (a*b)/GCD(a,b)
	return (nN1 * nN2) / GCDFast(nN1, nN2);
}

int main(int nArgv, char** pArgc) {
	long long n1, n2;
	std::cin >> n1 >> n2;
	std::cout << LCMFast(n1, n2);
	return 0;
}
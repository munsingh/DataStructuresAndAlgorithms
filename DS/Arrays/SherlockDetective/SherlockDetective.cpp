#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], hash_t[n + 1] = { 0 };
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			hash_t[a[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			if (hash_t[i] == 0) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
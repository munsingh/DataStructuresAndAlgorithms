#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(size_t nNumberOfStops, size_t nTank, vector<size_t> & vecStops) {
	size_t nCurrent = 0;
	size_t nPrevious = nCurrent;
	int nNumberOfRefuel = 0;

	while (nCurrent <= nNumberOfStops) {
		nPrevious = nCurrent;
		while (nCurrent <= nNumberOfStops && vecStops[nCurrent + 1] - vecStops[nPrevious] <= nTank) {
			++nCurrent;
		}

		if (nCurrent == nPrevious) {
			nNumberOfRefuel = -1;
			break;
		}

		if (nCurrent <= nNumberOfStops) {
			nNumberOfRefuel++;
		}
	}

    return nNumberOfRefuel;
}


int main() {
    size_t nDistance = 0;
    cin >> nDistance;
    size_t nTank = 0;
    cin >> nTank;
    size_t nNumberOfStops = 0;
    cin >> nNumberOfStops;

    vector<size_t> vecStops(nNumberOfStops + 2);
	vecStops[0] = 0;
    for (size_t i = 1; i < nNumberOfStops + 1; ++i)
        cin >> vecStops.at(i);
	vecStops[vecStops.size() - 1] = nDistance;
    cout << compute_min_refills(nNumberOfStops, nTank, vecStops) << "\n";

    return 0;
}

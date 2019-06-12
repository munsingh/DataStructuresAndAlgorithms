#include <vector>
#include <iostream>
#include <utility>
#include <random>

template <class T>
void CountPointsInSegmentsNaive(std::vector<T>& vecStarts,
								std::vector<T>& vecEnds,
								std::vector<T>& vecPoints,
								std::vector<T>& vecPointCounts) {
	//The naive approacj iterates through the start and end points
	//and if the point lies within the point increments the Point Found count 
	//of that point
	size_t nNumberOfSegments = vecStarts.size();
	size_t nNumberOfPoints = vecPointCounts.size();

	for (size_t i = 0; i < nNumberOfSegments; i++) {
		for (size_t j = 0; j < nNumberOfPoints; j++) {
			if (vecPoints[j] >= vecStarts[i] && vecPoints[j] <= vecEnds[i]) {
				vecPointCounts[j]++;
			}
		}
	}
}

template <class T>
bool LessThan(std::pair< T, int >& oPair1,
			  std::pair< T, int >& oPair2) {
	return oPair1.first < oPair2.first ||
		(oPair1.first == oPair2.first &&
			oPair1.second < oPair2.second);
}

template <class T>
bool EqualTo(std::pair< T, int >& oPair1,
			 std::pair< T, int >& oPair2) {
	return oPair1.first == oPair2.first &&
		oPair1.second == oPair2.second;
}

template <class T>
bool LessThanEqualTo(std::pair< T, int >& oPair1,
					 std::pair< T, int >& oPair2) {
	return LessThan(oPair1, oPair2) || EqualTo(oPair1, oPair2);
}

const int LEFT = 1;
const int RIGHT = 2;
const int POINT = 3;

template <class T>
int Partition(std::vector<std::pair<T, int>>& vecPointsAndSegments,
				 int nLeft,
				 int nRight) {
	std::pair< T, int> nPivot = vecPointsAndSegments[nLeft];
	int nPartition = nLeft + 1;
	for (int i = nLeft + 1; i <= nRight; i++) {
		//now check if pivot is greater than the element
		//if it is then swap them
		//Note, we have to compare using the 1st value in the pair
		if (LessThanEqualTo(vecPointsAndSegments[i], nPivot)) {
			std::swap(vecPointsAndSegments[nPartition],
					  vecPointsAndSegments[i]);
			nPartition++;
		}
	}

	std::swap(vecPointsAndSegments[nPartition - 1], vecPointsAndSegments[nLeft]);

	return nPartition - 1;
}
template <class T>
void RandomizedQuickSort(std::vector< std::pair<T, int>>& vecPointsAndSegments,
						 int nLeft, 
						 int nRight) {
	if (nLeft >= nRight) {
		return;
	}

	std::random_device oRandomDevice;
	std::mt19937 oRng( oRandomDevice());
	std::uniform_int_distribution<T> oDist(nLeft, nRight);
	int nRandomNumber = oDist(oRng);

	//swap the elements at nRandomNumber and nLeft
	std::swap(vecPointsAndSegments[nRandomNumber], vecPointsAndSegments[nLeft]);
	int nPartition = Partition(vecPointsAndSegments, nLeft, nRight);
	RandomizedQuickSort(vecPointsAndSegments, nLeft, nPartition - 1);
	RandomizedQuickSort(vecPointsAndSegments, nPartition + 1, nRight);
}

template <class T>
void CountPointsInSegments( std::vector<T>& vecStarts,
							std::vector<T>& vecEnds,
							std::vector<T>& vecPoints,
							std::vector<T>& vecPointCounts) {
	//A fast approach is to create a vector of elements as follows
	//pair(vecStart[i], LEFT)
	//pair(vecEnds[i], RIGHT)
	//pair(vecPoints, POINT)
	size_t nTotalPairs = vecStarts.size() + vecEnds.size() + vecPoints.size();
	size_t nIndex = 0;

	std::vector< std::pair< T, int >> vecPointsAndSegments(nTotalPairs);

	//create the pairs vecStart[i], LEFT
	for (size_t i = 0; i < vecStarts.size(); i++) {
		vecPointsAndSegments[nIndex++] = std::make_pair(vecStarts[i], LEFT);
	}

	//create the pairs vecEnds[i], RIGHT
	for (size_t i = 0; i < vecEnds.size(); i++) {
		vecPointsAndSegments[nIndex++] = std::make_pair(vecEnds[i], RIGHT);
	}

	//create the pairs vecPoints[i], POINT
	for (size_t i = 0; i < vecPoints.size(); i++) {
		vecPointsAndSegments[nIndex++]=std::make_pair(vecPoints[i], POINT);
	}

	//Now sort the vecPointAndSegments based on the first element of the pair
	//Use RandomizedQuikSort
	RandomizedQuickSort(vecPointsAndSegments, 
						0, 
						static_cast< int >(vecPointsAndSegments.size() - 1));

	//the vecPointsAndSegments are sorted
	//it contains sorted pairs of numbers in the form of 
	//[a[i], LEFT/RIGHT/POINT]
	//So now we have to count how many left/rights are present before a point
	//so each left increment the count, each right decrement the count
	
	//iterate over the vecPointsAndSegments array
	int nCount = 0;
	for (size_t i = 0; i < vecPointsAndSegments.size(); i++) {
		switch (vecPointsAndSegments[i].second) {
			case LEFT:
				nCount++;
				break;
			case RIGHT:
				nCount--;
				break;
			case POINT: {
				//update the vecPoints vector
				//value of nCount is the number of times
				//the point in the pair at position i
				//exists in the given line segments.
				//we know the point
				//From the point find at which position does the 
				//point occur in the vecPoints vector
				//We need to update this value in the same vecPointsCount
				//vector
				int j = 0;
				for (j = 0; j < vecPoints.size(); j++) {
					if (vecPoints[j] == vecPointsAndSegments[i].first) {
						break;
					}
				}

				//j is the index whose count we have found
				vecPointCounts[j] = nCount;
				break;
			}
			default:
				break;
		}
	}
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	int nNumberOfSegments, nNumberOfPoints;
	std::cin >> nNumberOfSegments >> nNumberOfPoints;

	std::vector< int > vecStarts(nNumberOfSegments);
	std::vector< int > vecEnds(nNumberOfSegments);

	for (int i = 0; i < nNumberOfSegments; i++) {
		std::cin >> vecStarts[i] >> vecEnds[i];
	}

	std::vector<int> vecPoints(nNumberOfPoints);
	std::vector<int> vecPointCounts(nNumberOfPoints);
	for (int i = 0; i < nNumberOfPoints; i++) {
		std::cin >> vecPoints[i];
	}

	//CountPointsInSegmentsNaive(vecStarts, vecEnds, vecPoints, vecPointCounts);
	CountPointsInSegments(vecStarts, vecEnds, vecPoints, vecPointCounts);

	for (int i = 0; i < nNumberOfPoints; i++) {
		std::cout << vecPointCounts[i] << " ";
	}

	return 0;
}
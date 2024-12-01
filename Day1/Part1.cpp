#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	vector<int> leftList;
	vector<int> rightList;
		
	int x, y;

	while (cin >> x >> y) {
		leftList.push_back(x);
		rightList.push_back(y);
	}

	sort(leftList.begin(), leftList.end());
	sort(rightList.begin(), rightList.end());

	int totalDistance = 0;

	for (int i = 0; i < leftList.size(); i++) {
		totalDistance += abs(leftList[i] - rightList[i]);
	}
	
	cout << totalDistance;
	return 0;
}

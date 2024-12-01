#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main()
{
	vector<int> leftList;
	unordered_map<int, int> rightListMap;

	int x, y;

	while (cin >> x >> y) {
		leftList.push_back(x);
		rightListMap[y]++;
	}
		
	int similarityScore = 0;

	for (int n : leftList) {
		similarityScore += n * rightListMap[n];
	}
	
	cout << similarityScore;
	return 0;
}

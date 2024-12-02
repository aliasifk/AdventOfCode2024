#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
int main()
{
	vector<vector<int>> reports;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            break; 
        }

        stringstream ss(line);
        vector<int> report;
        int level;

        while (ss >> level) {
            report.push_back(level);
        }

        reports.push_back(report); 
    }
    
    int safeReportsCount = 0;

    for (vector<int> report : reports) {
        bool isSafe = true;
        bool isIncreasing = false;
        bool isDecreasing = false;

        for (int i = 0; i < report.size() - 1;i++) {
            bool inc = report[i] < report[i + 1];
            bool dec = report[i] > report[i + 1];
            int distanceNext = abs(report[i] - report[i + 1]);

            if (isIncreasing && dec || isDecreasing && inc || distanceNext == 0 || distanceNext > 3) {
                isSafe = false;
                break;
            }
            
            isIncreasing = inc;
            isDecreasing = dec;

        }

        if (isSafe) {
            safeReportsCount++;
        }
    }

    cout << safeReportsCount;

	return 0;
}

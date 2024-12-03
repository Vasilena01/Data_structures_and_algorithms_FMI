#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// First solution
void getIndiciesWhichSumToX()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, n;
		cin >> x >> n;
		unordered_map<int, int> map;
		for (int j = 0; j < n; j++)
		{
			int curr;
			cin >> curr;
			int target = x - curr;

			if (map.find(target) != map.end()) {
				cout << map[target] << " " << j + 1 << endl;
				break;
			}

			map[curr] = j + 1;
		}
	}
}

// Second solution
void findIndicesWhichSumToX() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, n;
        cin >> x >> n;

        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }

        unordered_map<int, int> map;
        for (int j = 0; j < nums.size(); j++) {
            int curr = nums[j];
            int other = x - curr;

            if (map.find(other) != map.end()) {
                cout << map[other] + 1 << " " << j + 1 << endl;
                break;
            }

            map[curr] = j;
        }
    }
}
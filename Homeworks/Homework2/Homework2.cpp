#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "ExtraLeetCodeTask1.h"

int main()
{
	/*Task 1
	int p, n;
	cin >> p >> n;
	int level = 1;
	
	for (int i = 0; i < n; i++)
	{
		int target;
		cin >> target;
		cout << customTernarySearchRecursively(1, pow(3, p), target, level) << endl;
		level = 1;
	}*/

	/*Task 2
	int n, k;
	cin >> n >> k;
	vector<int> weights(n);
	vector<pair<int, int>> weightIntervals;

	for (int i = 0; i < n; i++)
		cin >> weights[i];

	for (int i = 0; i < k; i++)
	{
		int first, second;
		cin >> first >> second;
		weightIntervals.push_back({ first, second });
	}

	getNumberOfPlayers(weights, weightIntervals);*/

	/*Task 3
	int n, k;
	cin >> n >> k;
	vector<int> skills(n);
	for (int i = 0; i < n; i++)
		cin >> skills[i];

	cout << minimizeMaxSum(skills, k);*/

	/*Extra tasks from leet code*/
	vector<int> nums = { 3, 1 };
	cout << findMin(nums);
}
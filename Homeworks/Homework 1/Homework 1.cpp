#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task3QuickSort.h"

int main()
{
    /*Task 1
    int n;
    cin >> n;
    vector<char> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sortArray(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i];*/

    /*Task 2
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<double> medians(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        medians[i] = getMedian(arr, n - i - 1);
    }

    for (int i = 0; i < n; i++)
        cout << medians[i] << endl;*/

    /*Task 3 - slow - bubble sort
    int n;
    cin >> n;

    vector<string> names(n);
    vector<int> grades(n);

    for (int i = 0; i < n; i++)
        cin >> names[i];

    for (int i = 0; i < n; i++)
        cin >> grades[i];

    sortByGrade(names, grades);
    for (int i = n - 1; i >= 0; i--)
        cout << names[i] << " " << grades[i] << endl;*/

    /*Task 3 - fast - quick sort*/
    int n;
    cin >> n;

    vector<pair<string, int>> results(n);
    for (int i = 0; i < n; i++)
    {
        cin >> results[i].first;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> results[i].second;
    }

    sortResults(results, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << results[i].first << " " << results[i].second << endl;
}
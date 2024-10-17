#pragma once
#include <iostream>
#include <vector>
using namespace std;

int getRecalculatedNum(char curr)
{
    if (curr >= '0' && curr <= '9')
        return curr - '0'; // 1-10 (-48)
    else if (curr >= 'A' && curr <= 'Z')
        return curr - 28 - 1; // 37-62
    else if (curr >= 'a' && curr <= 'z')
        return curr - 86 - 1; // 11-36
    return 0;
}

void sortArray(vector<char>& arr, int n)
{
    // Solution
    vector<int> count(62, 0);
    vector<char> output(n);

    // Counting the occurences of each element in arr
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int index = getRecalculatedNum(arr[i]);
        count[index]++;
    }

    // Updating the count array based on the cumulative counts
    for (int i = 1; i < 62; i++)
    {
        count[i] += count[i - 1];
    }

    // Placing the elements in the correct order in the output array
    for (int i = n - 1; i >= 0; i--)
    {
        int index = getRecalculatedNum(arr[i]);
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
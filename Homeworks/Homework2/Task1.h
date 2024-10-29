#pragma once
#include <iostream>
#include <vector>

using namespace std;

int customTernarySearchRecursively(long long l, long long r, int target, int& depth)
{
	if (l == r)
		return depth;

	long long mid1 = l + (r - l) / 3;
	long long mid2 = r - (r - l) / 3;

	if (target <= mid1)
	{
		depth++;
		return customTernarySearchRecursively(l, mid1,target, depth);
	}
	if (target >= mid2)
	{
		depth++;
		return customTernarySearchRecursively(mid2,r, target, depth);
	}

	if (target > mid1 && target < mid2)
		return depth;
}
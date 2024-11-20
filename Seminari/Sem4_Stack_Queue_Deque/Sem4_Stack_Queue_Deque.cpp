#include <iostream>
#include "AsteroidColision.h"
#include "NextGreaterElement.h"


int main()
{
	/*Asteroid colision
	vector<int> res;
	vector<int> input = { 5, 10, -5 };
	res = asteroidCollision(input);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";*/

	/*Next greater element*/
	vector<int> res;
	vector<int> input = { 5, 4, 3, 2, 1 };
	res = nextGreaterElements(input);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
}
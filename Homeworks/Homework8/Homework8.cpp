#include <iostream>
#include "BusDriver.h"
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << canGetAll() << endl;
	}
}
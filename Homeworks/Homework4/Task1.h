#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool matrix[1000][1000] = { 0 };

bool isEmpty(int x, int y, int rows, int cols)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return false;
    return matrix[x][y] == 0;
}

void getHealthyApplesCount()
{
    int rows, cols, days;
    cin >> rows >> cols >> days;

    Point p1, p2;
    cin >> p1.x >> p1.y;
    p1.x--;
    p1.y--;
    matrix[p1.x][p1.y] = 1;

    queue<Point> spoiled;
    spoiled.push(p1);

    while (cin >> p2.x >> p2.y)
    {
        p2.x--;
        p2.y--;
        matrix[p2.x][p2.y] = 1;
        spoiled.push(p2);
        break;
    }

    while (days > 0)
    {
        int size = spoiled.size();

        while (size > 0)
        {
            Point currApple = spoiled.front();
            // Removing the apple for now, so the others to come one forward
            spoiled.pop();

            if (isEmpty(currApple.x - 1, currApple.y, rows, cols))
            {
                matrix[currApple.x - 1][currApple.y] = 1;
                spoiled.push({ currApple.x - 1, currApple.y });
            }

            if (isEmpty(currApple.x + 1, currApple.y, rows, cols))
            {
                matrix[currApple.x + 1][currApple.y] = 1;
                spoiled.push({ currApple.x + 1, currApple.y });
            }

            if (isEmpty(currApple.x, currApple.y - 1, rows, cols))
            {
                matrix[currApple.x][currApple.y - 1] = 1;
                spoiled.push({ currApple.x, currApple.y - 1 });
            }

            if (isEmpty(currApple.x, currApple.y + 1, rows, cols))
            {
                matrix[currApple.x][currApple.y + 1] = 1;
                spoiled.push({ currApple.x, currApple.y + 1 });
            }

            // Push at the end again current, to have it for the final calc
            spoiled.push(currApple);
            size--;
        }
        days--;
    }

    cout << (rows * cols) - spoiled.size() << endl;
}

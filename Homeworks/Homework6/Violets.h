#pragma once
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

size_t sumFlowers(size_t n) {
    if (n == 1 || n == 2) {
        return 2;
    }

    size_t first = 2;
    size_t second = 2;

    for (size_t i = 3; i <= n; i++) {
        size_t temp = second;
        second += first;
        first = temp;
        second %= MOD;
        first %= MOD;
    }

    return second;
}
/*
 * Author: Rakhimberdi
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numRabbits(vector<int>& answers) {
    map<int, int> count;
    for (int x : answers) {
        count[x]++;
    }

    int rabbits = 0;
    for (auto [y, x] : count) {
        rabbits += (x + y) / (y + 1) * (y + 1);
    }
    return rabbits;
}



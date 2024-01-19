/*
 * Author: Rakhimberdi
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isSatisfied(vector<vector<int>>& formula, map<int, bool>& values) {
    for (auto& clause : formula) {
        bool clauseSatisfied = false;
        for (auto& var : clause) {
            if (var > 0 && values[var] || var < 0 && !values[-var]) {
                clauseSatisfied = true;
                break;
            }
        }
        if (!clauseSatisfied) {
            return false;
        }
    }
    return true;
}


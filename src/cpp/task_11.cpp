/*
 * Author: Rakhimberdi
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool evaluateFormula(vector<vector<int>>& formula, vector<bool>& assignment) {
    for (auto& clause : formula) {
        bool clauseSatisfied = false;
        for (auto& var : clause) {
            if ((var > 0 && assignment[var - 1]) || (var < 0 && !assignment[-var - 1])) {
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

bool isSatisfiable(vector<int>& variables, vector<vector<int>>& formula) {
    int numVariables = variables.size();
    for (int i = 0; i < pow(2, numVariables); i++) {
        vector<bool> assignment(numVariables);
        for (int j = 0; j < numVariables; j++) {
            assignment[j] = bool((i >> j) & 1);
        }
        if (evaluateFormula(formula, assignment)) {
            return true;
        }
    }
    return false;
}

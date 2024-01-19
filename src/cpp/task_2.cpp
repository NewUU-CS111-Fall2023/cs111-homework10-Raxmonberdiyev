/*
 * Author:Rakhimberdi
 * Date:
 * Name:
 */

#include <iostream>
#include <string>
using namespace std;

string turingAddition(string tape) {
    int state = 0;
    int i = 0;

    while (true) {
        switch (state) {
            case 0:
                if (tape[i] == '1') {
                    i++;
                } else if (tape[i] == '0') {
                    state = 1;
                    i++;
                }
                break;
            case 1:
                if (tape[i] == '1') {
                    tape[i] = 'X';
                    state = 2;
                    i--;
                } else if (tape[i] == 'X') {
                    i++;
                } else if (tape[i] == '0') {
                    tape[i] = '1';
                    state = 3;
                    i--;
                }
                break;
            case 2:
                if (tape[i] == '1') {
                    i--;
                } else if (tape[i] == '0') {
                    tape[i] = '1';
                    state = 0;
                    i++;
                }
                break;
            case 3:
                if (tape[i] == '1') {
                    i--;
                } else if (tape[i] == '0') {
                    return tape;
                }
                break;
        }
    }
}



/*
 * Author: Rakhimberdi
 * Date:
 * Name:
 */

#include <iostream>
#include <string>
using namespace std;

string turingCompare(string tape) {
    int state = 0;
    int i = 0;

    while (true) {
        switch (state) {
            case 0:
                if (tape[i] == '1') {
                    tape[i] = 'X';
                    i++;
                } else if (tape[i] == '0') {
                    state = 1;
                    i++;
                }
                break;
            case 1:
                if (tape[i] == '1') {
                    tape[i] = 'Y';
                    state = 2;
                    i--;
                } else if (tape[i] == 'Y') {
                    i++;
                } else if (tape[i] == '0') {
                    return "11";  // Second number is greater
                }
                break;
            case 2:
                if (tape[i] == 'X') {
                    tape[i] = '1';
                    state = 0;
                    i++;
                } else if (tape[i] == '1') {
                    i--;
                } else if (tape[i] == '0') {
                    return "1";
                }
                break;
        }
    }
}


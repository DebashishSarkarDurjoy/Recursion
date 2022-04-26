#include <iostream>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void keypadOutput(string input, string output, int i) {
    // base case
    if (input[i] == '\0') {
        cout << output << endl;
        return ;
    }

    // recursive case
    int current_digit = input[i] - '0';

    if (current_digit == 0 || current_digit == 1) {
        keypadOutput(input, output, i+1);
    }

    for (int k = 0; k < keypad[current_digit].size(); k++) {
        keypadOutput(input, output + keypad[current_digit][k], i + 1);
    }

    return ;
}

int main(void) {
    string input;
    cin >> input;

    string output;
    keypadOutput(input, output, 0);

    return 0;
}

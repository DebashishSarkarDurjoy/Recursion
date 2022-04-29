#include <iostream>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void smartKeypad(string input, string output, int i) {
    if (input[i] == '\0') {
        cout << output << endl;
        return ;
    }

    int current_digit = input[i] - '0';
    if (current_digit == 0 || current_digit == 1)
        smartKeypad(input, output, i+1);


    for (int k = 0; k < keypad[current_digit].size(); k++) {
        smartKeypad(input, output + keypad[current_digit][k], i+1);
    }


    return ;
}

int main(void) {
    string input;
    cin >> input;

    string output;

    smartKeypad(input, output, 0);

    return 0;
}

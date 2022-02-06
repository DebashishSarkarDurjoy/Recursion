#include<iostream>
#include<vector>
using namespace std;
vector<string> v;

void find_permutation(string inp, int i) {
    if (inp[i] == '\0') {
        // string str(inp);
        v.push_back(inp);
        return;
    }

    for (int j = i; inp[j] != 0; j++) {
        swap(inp[i], inp[j]);
        find_permutation(inp, i+1);
        swap(inp[i], inp[j]);
    }
}

int main(void) {
    string input;
    cin >> input;

    find_permutation(input, 0);

    for (auto ele: v) {
        cout << ele << endl;
    }

    return 0;
}

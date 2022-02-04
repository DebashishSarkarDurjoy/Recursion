#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int X) {
    if (n == i) {
        if (X == 0) return 1;
        return 0;
    }
    if (X < 0) return 0;

    int inc = countSubsets(arr, n, i+1, X-arr[i]);
    int exc = countSubsets(arr, n, i+1, X);

    return inc + exc;
}

int main(void) {
    vector<int> arr{1,2,3,20,4,5};
    int X = 10;

    cout << countSubsets(arr, arr.size(), 0, X) << endl;

    return 0;
}

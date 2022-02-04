#include <iostream>
using namespace std;

int countWays(int n) {
    if (n == 0 || n == 1) return 1;
    if (n < 0) return 0;

    int sum = 0;
    
    sum = countWays(n-1) + countWays(n-2) + countWays(n-3);



    return sum;
}

int main(void) {
    int n;
    cin >> n;
    cout << countWays(n) << endl;

    return 0;
}

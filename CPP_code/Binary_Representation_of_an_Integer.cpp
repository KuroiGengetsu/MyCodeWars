/**
 * Binary Representation for an Integer:
 *   1 = 00000000000000000000000000000001 in 32 bit
 * return vector<int> bits = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
 */
#include <iostream>
#include <vector>

using namespace std;
vector<int> showBits(int n);

int main() {
    for (int x: showBits(-1))
        cout << x << ' ';
    cout << endl;
    return 0;
}


vector<int> showBits(int n0) {
    long long n = n0;
    vector<int> bits(32);
    n = (n < 0) ? (4294967296 + n) : n;
    for (int i = 31; i >= 0, n > 0; i--) {
        bits[i] = n % 2;
        n /= 2;
    }
    return bits;
}

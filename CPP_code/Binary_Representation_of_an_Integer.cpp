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


vector<int> showBits(long long n) {
    vector<int> bits(32);
    n = (n < 0) ? (4294967296 + n) : n;
    for (int i = 31; i >= 0, n > 0; i--) {
        bits[i] = n % 2;
        n /= 2;
    }
    return bits;
}

vector<int> showBits2(long long n) {
    vector<int> result(32);
    for (int i = 31; i >= 0; --i) {
        result[i] = n & 1;
        n >>= 1;
    }
    return result;
}

#include <bitser>
vector<int> showBits3(int n) {
    bitset<32> bm(n);
    vector<int> result(32, 0);
    for (int i = 0; i < 32; i++) {
        result[i] = bm[31 - i];
    }
    return result;
}

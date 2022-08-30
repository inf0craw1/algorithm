#include <bits/stdc++.h>

using namespace std;
typedef numeric_limits<long double> LDBL;

int main(void) {
    long double a, b;

    cin >> a >> b;
    a = 1;
    b = 3;
    cout.precision(LDBL::max_exponent);
    cout << a / b << endl;

    return 0;
}

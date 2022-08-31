#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int a, b, c;

    cin >> a >> b >> c;

    if ( a == b && b == c ) {
        cout << 10000 + a * 1000 << endl;
        return 0;
    }
    if ( a == b || a == c ) {
        cout << 1000 + 100 * a << endl; 
        return 0;
    }
    if ( b == c ) {
        cout << 1000 + 100 * b << endl;
        return 0;
    }
    cout << 100 * max(a, max(b, c)) << endl;

    return 0;
}


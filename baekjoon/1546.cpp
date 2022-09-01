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
typedef numeric_limits<long double> ldbl;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int n;
    long double avg, tmp = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        avg += tmp;
    }
    cout.precision(ldbl::max_limits10);
    cout << double(avg / n) << endl;

    return 0;
}


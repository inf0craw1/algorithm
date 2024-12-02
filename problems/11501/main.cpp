#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int testCases; cin >> testCases;

    for ( int k = 0; k < testCases; k++ ) {
        int days; cin >> days;
        vi prices, remainMax = vi(days, 0);
        ll res = 0;

        for ( int i = 0; i < days; i++ ) {
            int temp; cin >> temp;
            prices.push_back(temp);
        }

        ll curMax = 0;
        for ( int i = days-1; i >= 0; i-- ) {
            remainMax[i] = curMax;
            curMax = max(curMax, prices[i]);
        }

        for ( int i = 0; i < days; i++ ) {
            if ( prices[i] < remainMax[i] ) {
                res += remainMax[i] - prices[i];
            }
        }
        cout << res << endl;

    }

    return 0;
}

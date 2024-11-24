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
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
vector<vi> dp = vector<vi>(31, vi(31, 0));
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
ll getNumberOfCases(pi cur) {
    if ( dp[cur.fi][cur.se] != 0 ) return dp[cur.fi][cur.se];
    if ( cur.fi == 0 ) return 1;
    if ( cur.se== 0 ) return dp[cur.fi][cur.se] = getNumberOfCases({cur.fi - 1, cur.se + 1});
    return dp[cur.fi][cur.se] = getNumberOfCases({cur.fi, cur.se - 1}) + getNumberOfCases({cur.fi - 1, cur.se + 1});
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    while ( 1 ) {
        int n; cin >> n;

        if ( n == 0 ) break;

        cout << getNumberOfCases({n, 0}) << endl;

    }
    return 0;
}
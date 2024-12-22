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
int n;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
void getCombination(int len, string curStr) {
    if ( len == n )  {

        vi counts = vi(n, 0);

        for ( auto c: curStr ) {
            int num = c - '0';
            counts[num]++;
        }
        if ( counts[1] <= counts[2] && counts[2] <= counts[3] ) {
            cout << curStr << endl;
        }
        return;
    }

    for ( int i = 1; i <= 3; i++ ) {
        getCombination(len+1, curStr + to_string(i));
    }
 
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> n;

    getCombination(0, "");

    return 0;
}

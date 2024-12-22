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

    int testcases; cin >> testcases;

    for ( int k = 0; k < testcases; k++ ) {

        int maxM, maxN, targetM, targetN; cin >> maxM >> maxN >> targetM >> targetN;

        int curYear = targetM;
        int chk = 0;

        for ( ; curYear <= maxM * maxN; curYear += maxM ) {
            int curN = curYear % maxN;
            if ( curN == 0 ) curN = maxN;
            if ( curN == targetN ) {
                chk = 1;
                break;
            } 
        }

        if ( chk == 0 ) {
            cout << -1 << endl;
            continue;
        }

        cout << curYear << endl;



    }
    

    return 0;
}
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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int n; cin >> n;

    vi stck, height, res = vi(n, 0);

    for ( int i = 0; i < n; i++ ) {
        int temp; cin >> temp;

        height.push_back(temp);
    }

    for ( int i = 0; i < n; i++ ) {
        while ( stck.size() ) {
            if ( height[stck.back()] >= height[i] ) break;
            stck.pop_back();
        }
        if ( stck.size() ) {
            res[i] = stck.back() + 1;
        }
        stck.push_back(i);
    }

    for ( auto r: res ) {
        cout << r << ' ';
    }
    cout << endl;



    return 0;
}

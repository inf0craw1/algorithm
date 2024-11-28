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
void printStck(vi stck) {
    cout << "-----------------------" << endl;
    for ( auto s: stck ) {
        cout << s << ' ';
    }
    cout << endl;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    vi stck;
    vector<char> res;
    int n; cin >> n;
    int cur = 1;

    for ( int i = 0; i < n; i++ ) {
        int target; cin >> target;

        while ( cur <= target ) {
            res.push_back('+');
            stck.push_back(cur++);
        }

        while ( stck.size() && stck.back() != target ) {
            res.push_back('-');
            stck.pop_back();
        }
        
        if ( !stck.size() ) {
            cout << "NO" << endl;
            return 0;
        }

        res.push_back('-');
        stck.pop_back();
    }

    for ( auto r: res ) {
        cout << r << endl;
    }
    

    return 0;
}
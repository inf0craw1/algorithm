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

    int n; cin >> n;

    for ( int i = 0; i < n; i++ ) {
        string curStr; cin >> curStr;
        vector<char> res, buf;

        for ( auto cur: curStr ) {
            if ( cur == '<' ) {
                if ( !res.size() ) continue;
                buf.push_back(res.back());
                res.pop_back();
                continue;
            }
            if ( cur == '>' ) {
                if ( !buf.size() ) continue;
                res.push_back(buf.back());
                buf.pop_back();
                continue;
            }
            if ( cur == '-' ) {
                if ( !res.size() ) continue;
                res.pop_back();
                continue;
            }
            res.push_back(cur);
        }
        while ( buf.size() ) {
            res.push_back(buf.back());
            buf.pop_back();
        }
        for ( auto r: res ) {
            cout << r;
        }
        cout << endl;
    }

    return 0;
}

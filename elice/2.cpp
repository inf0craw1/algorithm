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
    vvi mapp;
    for ( int i = 0; i < n; i++ ) {
        vi tempRow;
        for ( int j = 0; j < n; j++ ) {
            int temp; cin >> temp;
            tempRow.push_back(temp);
        }
        mapp.push_back(tempRow);
    }

    int targetRow, targetCol; cin >> targetRow >> targetCol;
    int targetNum = mapp[targetRow-1][targetCol-1];

    for ( int i = targetRow-1; i < n; i++ ) {
        for ( int j = targetCol-1; j < n; j++ ) {
            if ( mapp[i][j] < targetNum ) mapp[i][j] = 0;
        }
    }

    for ( auto row: mapp ) {
        for ( auto col: row ) {
            cout << col << ' ';
        }
        cout << endl;
    }

    return 0;
}

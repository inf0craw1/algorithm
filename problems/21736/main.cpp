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
int height, width;
vvi mapp, isVisit;
pi startXY;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool isSafe(pi cur) {
    if ( cur.fi < 0 || cur.fi >= height || cur.se < 0 || cur.se >= width ) return false;
    return true;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> height >> width;

    isVisit = vvi(height, vi(width, 0));

    for ( int i = 0; i < height; i++ ) {
        vi tempRow;
        for ( int j = 0; j < width; j++ ) {
            char cur; cin >> cur;
            if ( cur == 'O' ) {
                tempRow.push_back(0);
                continue;
            }

            if ( cur == 'I' ) {
                tempRow.push_back(0);
                startXY.fi = i;
                startXY.se = j;
                continue;
            }

            if ( cur == 'P' ) {
                tempRow.push_back(1);
                continue;
            }

            tempRow.push_back(-1);
        }
        mapp.push_back(tempRow);
    }

    for ( int i = 0; i < height; i++ ) {
        for ( int j = 0; j < width; j++ ) {
            cout << mapp[i][j] << ' ';
        }
        cout << endl;
    }

    queue<pi> q;
    q.push(startXY);

    while (q.size()) {
        pi cur = q.front();
        q.pop();

        cout << cur.fi << ',' << cur.se << endl;

    }

    

    return 0;
}

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
vvi mapp, isVisit;
int targetRow, targetCol;
vector<pi> directions = { { -1, -1 }, {-1, 1}, {1, -1}, {1, 1} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool isSafe(pi cur) {
    if ( cur.fi < 0 || cur.se < 0 || cur.fi >= n || cur.se >= n ) return false;
    return true;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> n;
    
    isVisit = vvi(n, vi(n, 0));
    for ( int i = 0; i < n; i++ ) {
        vi tempRow;
        for ( int j = 0; j < n; j++ ) {
            int temp; cin >> temp;
            tempRow.push_back(temp);
        }
        mapp.push_back(tempRow);
    }
    cin >> targetRow >> targetCol;

    queue<pi> q;
    q.push({targetRow-1, targetCol-1});
    isVisit[targetRow-1][targetCol-1] = 1;


    while ( q.size() ) {
        pi cur = q.front();
        q.pop();

        for ( auto d: directions ) {
            pi newPos = { cur.fi + d.fi, cur.se + d.se };
            if ( !isSafe(newPos) ) continue;
            if ( isVisit[newPos.fi][newPos.se] ) continue;
            if ( mapp[newPos.fi][newPos.se] == 1 ) continue;
            q.push(newPos);
            isVisit[newPos.fi][newPos.se] = 1;

        }
    }

    for ( auto row: isVisit ) {
        for ( auto col: row ) {
            cout << col << ' ';
        }
        cout << endl;
    }


    return 0;
}

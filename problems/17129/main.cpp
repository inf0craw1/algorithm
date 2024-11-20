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
vector<vi> mmap;
vector<pi> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int row, col;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int isSafe(pi curPos) {
    if ( curPos.fi < 0 || curPos.se < 0 || curPos.fi >= row || curPos.se >= col ) return 0;
    return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> row >> col;
    char charTemp;
    int temp, maxi = 0;
    queue<pair<pi, int>> q;
    
    for ( int i = 0; i < row; i++ ) {
        vi temp_row;
        for ( int j = 0; j < col; j++ ) {
            cin >> charTemp;
            temp = charTemp - '0';

            if ( temp == 2) {
                q.push(make_pair(make_pair(i, j), 0));
                temp_row.push_back(1);
                continue;
            }
            temp_row.push_back(temp);
        }
        mmap.push_back(temp_row);
    }

    while ( q.size() ) {
        pair<pi, int> cur = q.front();
        q.pop();
        pi curPos = cur.fi;
        int curStep = cur.se;

        if ( curStep != 0 && mmap[curPos.fi][curPos.se] == 1 ) continue;

        if ( mmap[curPos.fi][curPos.se] > 1 ) {
            cout << "TAK" << endl << curStep << endl;
            return 0;
        }

        mmap[curPos.fi][curPos.se] = 1;

        for ( auto d: directions ) {
            pi newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);

            if ( !isSafe(newPos) ) continue;
            if ( mmap[newPos.fi][newPos.se] == 1 ) continue;

            q.push(make_pair(newPos, curStep+1));
        }
    }

    cout << "NIE" << endl;



    return 0;
}

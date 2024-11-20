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
int row, col;
vector<vi> mmap;
vector<pi> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int isSafe(pi pos) {
    if ( pos.fi < 0 || pos.se < 0 || pos.fi >= row || pos.se >= col ) return 0;
    return 1;
}

void removeConnectedGrass(pi pos) {
    queue<pi> q;

    q.push(pos);

    while ( q.size() ) {
        pi curPos = q.front();
        q.pop();

        mmap[curPos.fi][curPos.se] = 0;
        
        for ( auto d: directions ) {
            pi newPos = make_pair(curPos.fi + d.fi, curPos.se + d.se);
            if ( !isSafe(newPos) ) continue;
            if ( mmap[newPos.fi][newPos.se] == 0 ) continue;
            q.push(newPos);
        }
    }
}


/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    char temp;
    int cnt = 0;

    cin >> row >> col;

    for ( int i = 0; i < row; i++ ) {
        vi temp_row;
        for ( int j = 0; j < col; j++ ) {
            cin >> temp;

            temp_row.push_back(temp == '.' ? 0 : 1);
        }
        mmap.push_back(temp_row);
    }

    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            if ( mmap[i][j] == 1 ) {
                removeConnectedGrass(make_pair(i, j));
                cnt ++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
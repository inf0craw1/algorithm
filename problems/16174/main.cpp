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
int mapSize, res = 0;
vector<pi> directions = { {0, 1}, {1, 0} };
vvi mmap;
vector<vector<bool>> chk;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int isSafe(pi pos) {
    if ( pos.fi < 0 || pos.se < 0 || pos.fi >= mapSize || pos.se >= mapSize ) return 0;
    return 1;
}

void findRoute(pi curPos) {
    if ( mmap[curPos.fi][curPos.se] == -1 ) {
        res = 1;
        return;
    } 
    if ( res != 0 ) return;

    chk[curPos.fi][curPos.se] = true;

    int curNum = mmap[curPos.fi][curPos.se];

    for ( auto d: directions ) {
        pi newPos = { curPos.fi + d.fi * curNum, curPos.se + d.se * curNum };
        if ( !isSafe(newPos) ) continue;
        if ( chk[newPos.fi][newPos.se] ) continue;

        findRoute(newPos);
    }

    return;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> mapSize;

    chk = vector<vector<bool>>(mapSize, vector<bool>(mapSize, false));

    for ( int i = 0; i < mapSize; i++ ) {
        vi tempRow;
        for ( int j = 0; j < mapSize; j++ ) {
            int temp; cin >>temp;
            tempRow.push_back(temp);
        }
        mmap.push_back(tempRow);
    }

    findRoute({0, 0});

    if ( res == 1 ) {
        cout << "HaruHaru" << endl;
        return 0;
    }
    cout << "Hing" << endl;
    

    return 0;
}

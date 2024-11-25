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
int width, height, remainCheese;
vvi mmap;
vector<vector<bool>> isVisit;
vector<pi> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} }, meltingCheeses;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool isSafe(pi cur) {
    if ( cur.fi < 0 || cur.se < 0 || cur.fi >= height || cur.se >= width ) return false;
    return true;
}

void fillAir(pi cur) {
    if ( isVisit[cur.fi][cur.se] ) return;
    isVisit[cur.fi][cur.se] = true;

    for ( auto d: directions ) {
        pi newPos = { cur.fi + d.fi, cur.se + d.se };
        if ( !isSafe(newPos) ) continue;
        if ( isVisit[newPos.fi][newPos.se] ) continue;
        if ( mmap[newPos.fi][newPos.se] == 1 ) continue;
        fillAir(newPos);
    }
}

void checkMeltingCheese(pi cur) {
    if ( isVisit[cur.fi][cur.se] ) return;
    isVisit[cur.fi][cur.se] = true;

    int airCnt = 0;

    for ( auto d: directions ) {
        pi newPos = { cur.fi + d.fi, cur.se + d.se };
        if ( !isSafe(newPos) ) continue;
        if ( !mmap[newPos.fi][newPos.se] && isVisit[newPos.fi][newPos.se] ) airCnt ++;
    }

    if ( airCnt >= 2 ) meltingCheeses.push_back(cur);
    for ( auto d: directions ) {
        pi newPos = { cur.fi + d.fi, cur.se + d.se };
        if ( !isSafe(newPos) ) continue;
        if ( mmap[newPos.fi][newPos.se] == 1 ) checkMeltingCheese(newPos);
    }
}

void printMap() {
    cout << "--------------------" << endl;
    for ( auto row: mmap ) {
        for ( auto col: row ) {
            if ( col == 1 ) {
                cout << "\033[1;31m" << col << "\033[0m ";
                continue;
            }
            cout << col << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> height >> width;

    for ( int i = 0; i < height; i++ ) {
        vi tempRow;
        for ( int j = 0; j < width; j++ ) {
            int temp; cin >> temp;
            if ( temp ) remainCheese ++;
            tempRow.push_back(temp);
        }
        mmap.push_back(tempRow);
    }

    int time = 1;
    while ( 1 ) {

        isVisit = vector<vector<bool>>(height, vector<bool>(width, false));

        fillAir({0, 0});
    
        meltingCheeses = {};
        for ( int i = 0; i < height; i++ ) {
            for ( int j = 0; j < width; j++ ) {
                if ( !isVisit[i][j] && mmap[i][j] == 1 ) checkMeltingCheese({i, j});
            }
        }

        for ( auto m: meltingCheeses ) {
            mmap[m.fi][m.se] = 0;
            remainCheese --;
        }

        if ( remainCheese <= 0 ) break;

        time ++;
    }

    cout << time << endl;


    return 0;
}

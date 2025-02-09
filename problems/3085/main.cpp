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
vector<pair<int, int>> directions = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
vector<vector<char>> mmap;
int n;
/* ----------------------------------------------- */


/* - FUNCTIONS ----------------------------------- */
bool isSafe(pair<int, int> pos) {
    if ( pos.fi < 0 || pos.se < 0 || pos.fi >= n || pos.se >= n ) return false;
    return true;
}

int getMax(pair<int, int> pos) {
    int maxi = 0, cur = 0;
    char lastChar = '0';

    for ( int i = 0; i < n; i++ ) {
        if ( lastChar != mmap[pos.fi][i] ) {
            maxi = max(maxi, cur);
            cur = 1;
            lastChar = mmap[pos.fi][i];
            continue;
        }
        cur++;
        maxi = max(maxi, cur);
    }
    cur = 0;
    lastChar = '0';

    for ( int i = 0; i < n; i++ ) {
        if ( lastChar != mmap[i][pos.se] ) {
            maxi = max(maxi, cur);
            cur = 1;
            lastChar = mmap[i][pos.se];
            continue;
        }
        cur++;
        maxi = max(maxi, cur);
    }

    return maxi;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int maxi = 0;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        vector<char> temp_row;
        for ( int j = 0; j < n; j++ ) {
            char temp; cin >> temp;
            temp_row.push_back(temp);
        }
        mmap.push_back(temp_row);
    }

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            pair<int, int> cur = {i, j};
            
            for ( auto d: directions ) {
                pair<int, int> target = {cur.fi + d.fi, cur.se + d.se};

                if ( !isSafe(target) ) continue;

                char temp = mmap[cur.fi][cur.se];
                mmap[cur.fi][cur.se] = mmap[target.fi][target.se];
                mmap[target.fi][target.se] = temp;

                int res = getMax(cur);
                maxi = max(maxi, res);

                temp = mmap[cur.fi][cur.se];
                mmap[cur.fi][cur.se] = mmap[target.fi][target.se];
                mmap[target.fi][target.se] = temp;
            }
        }
    }

    cout << maxi << endl;

    return 0;
}

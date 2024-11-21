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
int n;
vector<pi> directions = { {0, 1}, {1, 0} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int isSafe(pi pos) {
    if ( pos.fi >= n || pos.se >= n ) return 0;
    return 1;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> n;
    vector<vi> mmap, chk = vector<vi>(n, vi(n, 0));
    queue<pi> q;

    for ( int i = 0; i < n; i++ ) {
        vi tempRow;
        for ( int j = 0; j < n; j++ ) {
            int temp; cin >> temp;

            tempRow.push_back(temp);
        }
        mmap.push_back(tempRow);
    }

    q.push(make_pair(0, 0));

    while ( q.size() ) {
        pi curPos = q.front();
        q.pop();
        if ( chk[curPos.fi][curPos.se] ) continue;
        chk[curPos.fi][curPos.se] = 1;

        if ( curPos.fi == n-1 && curPos.se == n-1 ) {
            cout << "HaruHaru" << endl;
            return 0;
        }

        int curNum = mmap[curPos.fi][curPos.se];

        for ( auto d: directions ) {
            pi newPos = make_pair(curPos.fi + d.fi * curNum, curPos.se + d.se * curNum);

            if ( !isSafe(newPos) ) continue;
            q.push(newPos);
        }
    }

    cout << "Hing" << endl;

    return 0;
}
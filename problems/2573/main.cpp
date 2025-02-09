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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> pl;

/* - GLOBAL VARIABLES ---------------------------- */
int height, width;
vvi mapp, seaMap;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

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

            tempRow.push_back(temp);
        }

        mapp.push_back(tempRow);
    }

    for ( int i = 0; i < height; i++ ) {
        for ( int j = 0; j < width; j++ ) {
            cout << mapp[i][j] << ' ';
        }
        cout << endl;
    }
    

    return 0;
}

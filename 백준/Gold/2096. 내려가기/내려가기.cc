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
vi maxMap = {0, 0, 0}, minMap = {0, 0, 0};
vector<vi> directions = { {0, 1}, {-1, 0, 1}, {-1, 0} };
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> n;


    for ( int i = 0; i < n; i++ ) {
        vi tempRow, curMinMap = {0, 0, 0}, curMaxMap = {0, 0, 0};

        for ( int j = 0; j < 3; j++ ) {
            ll maxi = 0, mini = INF;

            for ( auto d: directions[j] ) {
                maxi = max(maxi, maxMap[j+d]);
                mini = min(mini, minMap[j+d]);
            }

            curMinMap[j] = mini;
            curMaxMap[j] = maxi;
        }

        for ( int j = 0; j < 3; j++ ) {
            int temp; cin >> temp;

            minMap[j] = curMinMap[j] + temp;
            maxMap[j] = curMaxMap[j] + temp;
        }
    }

    cout << max(max(maxMap[0], maxMap[1]), maxMap[2]) << ' ';
    cout << min(min(minMap[0], minMap[1]), minMap[2]) << endl;

    return 0;
}
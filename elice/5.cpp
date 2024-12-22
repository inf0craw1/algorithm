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
ll n;
vvi mapp, maxMap;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool isSafe(pi pos) {
    if ( pos.fi < 0 || pos.se < 0 || pos.fi >= n || pos.se >= n ) return false;
    return true;
}
ll findMax(pi pos) {
    if ( maxMap[pos.fi][pos.se] != -99999 ) return maxMap[pos.fi][pos.se];
    ll maxi = -2e9;

    ll curNum = mapp[pos.fi][pos.se];

    if ( isSafe({pos.fi - 1, pos.se + 1}) ) {
        ll n1 = findMax({pos.fi-1, pos.se});
        ll n2 = findMax({pos.fi-1, pos.se+1});
        ll n3 = findMax({pos.fi, pos.se+1});

        maxi = max(n1, n3);
        maxi = max(maxi, n2);

        int curRes = maxi + curNum;

        maxMap[pos.fi][pos.se] = curRes;

        //cout << "curPos: " << pos.fi << ", " << pos.se << ", "<< "curRes: " << curRes << endl;
        
        return curRes;
    }
    if ( isSafe({pos.fi - 1, pos.se}) ) {
        ll n1 = findMax({pos.fi-1, pos.se});
        ll curRes = n1 + curNum;
        maxMap[pos.fi][pos.se] = curRes;

        //cout << "curPos: " << pos.fi << ", " << pos.se << ", "<< "curRes: " << curRes << endl;
        return curRes;
    }
    ll n1 = findMax({pos.fi, pos.se+1});
    ll curRes =  n1 + curNum;

    maxMap[pos.fi][pos.se] = curRes;

        //cout << "curPos: " << pos.fi << ", " << pos.se << ", "<< "curRes: " << curRes << endl;
    return curRes;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> n;
    
    for ( int i = 0; i < n; i++ ) {
        vi tempRow;
        for ( int j = 0; j < n; j++ ) {
            int temp; cin >> temp;
            tempRow.push_back(temp);
        }
        mapp.push_back(tempRow);
    }
    maxMap = vvi(n, vi(n, -99999));
    maxMap[0][n-1] = mapp[0][n-1];

    ll res = findMax({n-1, 0});

    cout << res << endl;
    return 0;
}

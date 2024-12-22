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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    ll n, targetNum; cin >> n >> targetNum;
    vector<ull> nums;
    map<ull, ull> count;
    ull res = 0;


    for ( int i = 0; i < n; i++ ) {
        ull temp; cin >> temp;
        nums.push_back(temp);
        auto foundCnt = count.find(temp);
        if ( foundCnt != count.end() ) {
            foundCnt->se ++;
            continue;
        }
        count.insert({temp, 1});
    }

    for ( int i = 0; i < n-1; i++ ) {
        ull curNum = nums[i];
        auto foundCnt = count.find(temp);
        if ( foundCnt != count.end() ) {
            continue;
        }
        foundCnt->se --;

        if ( targetNum % curNum != 0 ) continue;
        
        res += foundCnt.se;
    }
    
    cout << res << endl;



    return 0;
}

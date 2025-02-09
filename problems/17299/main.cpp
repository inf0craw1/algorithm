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
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int n; cin >>n;
    vi nums;
    vi freq(1000001, 0);
    vi ans;

    for ( int i = 0; i < n; i++ ) {
        int temp; cin >> temp;
        nums.push_back(temp);
        freq[temp]++;
    }

    vector<pi> stack;

    for ( int i = n - 1; i >= 0; i-- ) {
        int cur = nums[i];
        int curFreq = freq[cur];

        while ( stack.size() )  {
            pi top = stack.back();
            if ( top.fi <= curFreq ) {
                stack.pop_back();
                continue;
            }
            break;
        }

        ans.push_back(stack.size() ? stack.back().se : -1 );
        stack.push_back({curFreq, cur});
    }

    for ( int i = n - 1; i >= 0; i-- ) cout << ans[i] << ' ';
    cout << endl;


    return 0;
}

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

    vi nums, accs;
    ll n, acc = 0; cin >> n;
    ll mini = LINF, minIdx = -1;

    for ( int i = 0; i < n; i++ ) {
        int temp; cin >> temp;
        nums.push_back(temp);
    }

    sort(all(nums));

    for ( int i = 0; i < n; i++ ) {
        acc += nums[i];
        accs.push_back(acc);
    }

    for ( int i = 0; i < n; i++ ) {
        ll curDistance = (nums[i] * (i + 1)) - accs[i];
        curDistance += (accs[n-1] - accs[i]) - (nums[i] * (n - i - 1));
        if ( mini > curDistance ) {
            mini = curDistance;
            minIdx = nums[i];
        }
    }

    cout << minIdx << endl;

    return 0;
}
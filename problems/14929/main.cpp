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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int res = 0;
	int n; cin >> n;
	
	vi nums;

	for ( int i = 0; i < n; i++ ) {
		int temp; cin >> temp;
		nums.push_back(temp);
	}

	for ( int i = 0; i < n-1; i++ ) {
		for ( int j = i+1; j < n; j++ ) {
			res += nums[i] * nums[j];
		}
	}

	cout << res << endl;


    return 0;
}

#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int cases; cin >> cases;

	for ( int z = 0; z < cases; z++ ) {
		string str; cin >> str;
		int includeNum; cin >> includeNum;
		vector<vector<int>> alphaPositions(27);
		int mini = 2e9, maxi = -1;

		for ( int i = 0; i < str.size(); i++ ) {
			alphaPositions[str[i] - 'a'].push_back(i);
		}

		for ( auto al: alphaPositions ) {
			if ( al.size() < includeNum ) continue;

			for ( int i = 0; i < al.size() - includeNum + 1; i++ ) {
				int cur = al[i+includeNum-1] - al[i] + 1;

				mini = min(mini, cur);
				maxi = max(maxi, cur);
			}
		}

		if ( mini == 2e9 && maxi == -1 ) {
			cout << -1 << endl;
			continue;
		}
		cout << mini << ' ' << maxi << endl;
		
	}

    return 0;
}

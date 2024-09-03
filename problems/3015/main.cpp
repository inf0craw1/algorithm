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

	int n; cin >> n;
	vi stk;
	int res = 0;


	for ( int i = 0; i < n; i++ ) {
		int cur; cin >> cur;

		cout << "============== cur: " << cur << " ==================" << endl;

		if ( stk.size() && stk.back() < cur ) {
			cout << "stk.size() && stk.back() < cur" << endl;
			int lastSize = stk.back();
			stk.pop_back();
			int cnt = 1;
			while ( stk.size() && stk.back() < cur ) {
				int top = stk.back();
				stk.pop_back();

				if ( lastSize == top ) {
					cnt ++;
					continue;
				}
				cout << "res += cnt * 2 cnt - 1" << endl;
				lastSize = top;
				res += cnt * 2 + cnt * (cnt - 1) / 2;
				cnt = 0;
			}
			res += cnt;
			
		}

		stk.push_back(cur);
		for ( auto s: stk ) {
				cout << s << ' ';
			}
			cout << endl;

		cout << "res : " << res << endl << endl;
	}

	cout << res << endl;


    return 0;
}

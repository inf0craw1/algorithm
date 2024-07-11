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

	string str; cin >> str;
	string res;

	for ( auto s: str ) {
		if ( s == ')' ) {
			string tempStr = ""; 
			while ( res.back() != '(' ) {
				tempStr.push_back(res.back());
				res.pop_back();
			}
			res.pop_back();

			int count = res.back() - '0';
			res.pop_back();

			for ( int i = 0; i < count; i++ ) {
				res.append(tempStr);
			}
			continue;
		}
		res.push_back(s);
	}

	cout << res.size() << endl;
    return 0;
}

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

	int res = 0;
	int n; cin >> n;
	bool hasZero = false;
	priority_queue<int> plusQ, minusQ;

	for ( int i = 0; i < n; i++ ) {
		int temp; cin >> temp;

		if ( temp == 0 ) {
			hasZero = true;
			continue;
		}
		if ( temp == 1 ) {
			res += 1;
			continue;
		}
		if ( temp > 0 ) {
			plusQ.push(temp);
			continue;
		}
		minusQ.push(temp * -1);
	}

	while ( plusQ.size() > 1 ) {
		int n1 = plusQ.top();
		plusQ.pop();
		int n2 = plusQ.top();
		plusQ.pop();
		res += n1 * n2;
	}
	if ( plusQ.size() ) res += plusQ.top();
	while ( minusQ.size() > 1 ) {
		int n1 = minusQ.top() * -1;
		minusQ.pop();
		int n2 = minusQ.top() * -1;
		minusQ.pop();
		res += n1 * n2;
	}
	if ( minusQ.size() && !hasZero ) res += minusQ.top() * -1;

	cout << res << endl;

    return 0;
}

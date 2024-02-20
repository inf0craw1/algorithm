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

	int n; cin >> n;
	ll res = 0;
	priority_queue<ll> pq;

	for ( int i = 0; i < n; i++ ) {
		int temp; cin >> temp;
		pq.push(temp * -1);
	}
	while ( pq.size() > 1 ) {
		ll n1 = pq.top() * -1;
		pq.pop();
		ll n2 = pq.top() * -1;
		pq.pop();
		ll sum = n1 + n2;

		res += sum;
		pq.push(sum * -1);
	}

	cout << res << endl;

    return 0;
}

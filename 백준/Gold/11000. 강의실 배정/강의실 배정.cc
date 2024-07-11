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
bool Comp(pi a, pi b) {
	if ( a.se == b.se ) return a.fi < b.fi;
	return a.se < b.se;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;
	vector<pi> classes;
	priority_queue<int> pq;

	for ( int i = 0; i < n; i++ ) {
		int startAt, endAt; cin >> startAt >> endAt;

		classes.push_back({startAt, endAt});
	}

	sort(all(classes));

	for ( int i = 0; i < n; i++ ) {
		int startAt = classes[i].fi;
		int endAt = classes[i].se;

		if ( pq.size() == 0 ) {
			pq.push(-endAt);
			continue;
		}

		int mini = -pq.top();

		if ( mini <= startAt ) {
			pq.pop();
			pq.push(-endAt);
			continue;
		}

		pq.push(-endAt);
	}

	cout << pq.size() << endl;


    return 0;
}

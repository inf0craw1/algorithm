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

	int num, size; cin >> num >> size;
	priority_queue<pi> pq;

	for ( int i = 0; i < size; i++ ) {
		int temp; cin >> temp;
		
		pq.push(make_pair(-temp, i));

		while ( pq.size() ) {
			pi cur = pq.top();

			if ( cur.se < i - size + 1 ) {
				pq.pop();
				continue;
			} 
			
			cout << -cur.fi << ' ';
			break;
		}

	}

	for ( int i = size; i < num; i++ ) {
		int temp; cin >> temp;

		pq.push(make_pair(-temp, i));

		while ( pq.size() ) {
			pi cur = pq.top();

			if ( cur.se < i - size + 1 ) {
				pq.pop();
				continue;
			} 
			
			cout << -cur.fi << ' ';
			break;
		}
	}

	cout << endl;

    return 0;
}

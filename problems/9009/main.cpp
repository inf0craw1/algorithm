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
vi fibonacci = {0, 1};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n; cin >> n;

	for ( int i = 2; ; i++ ) {
		fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
		if ( fibonacci[i] > 10e9 ) break;
	}

	cout << fibonacci.size() << endl;

	for ( auto f: fibonacci ) {
		cout << f << ' ';
	}
	cout << endl;


	for ( int i = 0; i < n; i++ ) {
		int num; cin >> num;


	}

 
    return 0;
}

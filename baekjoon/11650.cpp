#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

/* - GLOBAL VARIABLES ---------------------------- */
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

bool comp(ll *a, ll *b) {
	return a[2] < b[2];
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num;
	ll n[100001][3]; 

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> n[i][0] >> n[i][1];
		n[i][2] = (n[i][0] + 100000) * 100000 + (n[i][1] + 100000);
	}

	sort(n, n + num, comp);

    return 0;
}

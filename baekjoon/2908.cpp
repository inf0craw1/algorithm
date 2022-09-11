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

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string a, b;
	int aa = 0, bb = 0;

	cin >> a >> b;

	for (int i = 2; i >= 0 ; i--) {
		aa *= 10;
		aa += a[i] - '0';
		bb *= 10;
		bb += b[i] - '0';
	}
	if (aa < bb) {
		cout << bb << endl;
		return 0;
	}
	cout << aa << endl;
    return 0;
}

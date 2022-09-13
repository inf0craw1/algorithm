#include <bits/stdc++.h>

#define debug if constexpr (LOCAL) std::cout
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

/* - global variables ---------------------------- */
 
/* ----------------------------------------------- */

/* - functions ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	string s;
	int times[27] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
	int res = 0;
	
	getline(cin, s);
	
	for ( int i = 0; i < s.length(); i++) {
		res += times[s[i] - 'A'];
	}

	cout << res << endl;
    return 0;
}

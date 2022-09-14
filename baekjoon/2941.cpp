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

	string s, croatia[8] = {"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};
	int res = 0;

	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 8; j++) {
			bool isEqual = true;
			for (int k = 0; k < croatia[j].length(); k++) {
				if ( croatia[j][k] != s[i+k] ) {
					isEqual = false;
					break;
				}
			}
			if (isEqual) {
				i += croatia[j].length() - 1;
				break;
			}
		}
		res++;
	}

	cout << res << endl;

    return 0;
}

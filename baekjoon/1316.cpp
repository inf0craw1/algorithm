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

	int n, i, j, res = 0;
	string temp;

	cin >> n;

	for (i = 0; i < n; i++) {

		bool alphabet[27] = {};
		cin >> temp;

		for (j = 0; j < temp.length(); j++) {
			if (j != temp.length() - 1 && temp[j] == temp[j+1]) continue;
			if (alphabet[temp[j] - 'a']) {
				break;
			}
			alphabet[temp[j] - 'a'] = true;
		}
		if (j == temp.length()) res++;
	}

	cout << res << endl;

    return 0;
}

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

	string s;
	int alphabet[27];
	fill(alphabet, alphabet + 27, -1);

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int current = s[i] - 'a';
		if (alphabet[current] == -1) {
			alphabet[current] = i;
		}		
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}
	cout << endl;

    return 0;
}

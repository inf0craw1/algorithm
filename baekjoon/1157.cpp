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
	int alphabet[27] = {};
	int maxi = -1, maxIndex = -1, isDuplicated = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			alphabet[s[i] - 'a']++;
			continue;
		}
		alphabet[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (maxi < alphabet[i]) {
			maxi = alphabet[i];
			maxIndex = i;
			isDuplicated = 0;
			continue;
		}
		if (maxi == alphabet[i]) {
			isDuplicated = 1;
		}
	}

	if (isDuplicated) {
		cout << '?' << endl;
		return 0;
	}
	cout << (char)('A' + maxIndex) << endl;
    return 0;
}

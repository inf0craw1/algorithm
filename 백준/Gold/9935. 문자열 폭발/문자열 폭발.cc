#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

/* - GLOBAL VARIABLES ---------------------------- */
int len, exLen;
vector<char> stck;
string str, exStr;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> str >> exStr;

	len = str.size();
	exLen = exStr.size();
	
	for ( int i = 0; i < len; i++ ) {
		stck.push_back(str[i]);
		
		if ( stck.size() >= exLen ) {
			bool isMatch = true;
			for ( int j = stck.size() - 1, k = exLen - 1; k >= 0 ; j--, k-- ) {
				if ( stck[j] != exStr[k] ) {
					isMatch = false;
					break;
				}
			}
			if ( isMatch ) {
				for ( int j = 0; j < exLen; j++ ) {
					stck.pop_back();
				}
			}
		}
	}
	
	if ( stck.empty() ) {
		cout << "FRULA" << endl;
		return 0;
	}

	for ( auto ss: stck ) {
		cout << ss;
	}
	cout << endl;

    return 0;
}

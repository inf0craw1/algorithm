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
string str, exStr;
int len, exLen;
vector<pi> skipParts;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
pi FindChainingExplosion(int s, int from, int jump) {
	cout << s << ' ' << from << ' ' << jump << endl;
	for ( int i = s; i < from ; i++ ) {
		bool chkFound = true;
		for ( int j = i, k = 0; k < exLen; j++, k++ ) {
			if ( j == from ) {
				j += jump;
				continue;
			}
			if ( str[j] != exStr[k] ) {
				chkFound = false;
				break;
			} 
		}
		if ( chkFound ) {
			pi res = FindChainingExplosion(max(0, i - exLen + 1), i, jump + exLen);
			return res;
		}
	}
	return make_pair(from, jump);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> str >> exStr;
	len = str.size();
	exLen = exStr.size();

	while ( 1 ) {
		cout << "==================" << endl;
		bool chkFound = false;
		int start = 0;
		while ( start < len ) {
			auto f = str.find(exStr, start);
			if ( f == string::npos ) {
				break;
			}
			chkFound = true;
			cout << "----------" << endl;
			cout << f << endl;
			pi res = FindChainingExplosion( max(0, (int)f - exLen + 1), f, exLen - 1);
			start = res.fi + res.se;
			skipParts.push_back(res);
		}

		string resStr = "";
		cout << "---------------------" << endl;
		for ( auto s: skipParts ) {
			cout << s.fi << ' ' << s.se << endl;
		}
		for ( int i = 0; i < len; i++ ) {
			for ( auto s: skipParts ) {
				if ( i == s.fi ) {
					i += s.se + 1;
					break;
				}
			}

			if ( i >= len ) break;
			
			resStr += str[i];
		}
		cout << resStr << endl;
		str = resStr;

		if ( !chkFound ) break;
	}

	if ( str == "" ) {
		cout << "FRULA" << endl;
		return 0;
	}
	cout << str << endl;

    return 0;
}

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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	bool isReversed = false;
	string str, targetStr; cin >> str >> targetStr;
	deque<char> dq;

	for ( int i = 0; i < targetStr.size(); i++ ) {
		dq.push_back(targetStr[i]);
	}
	while ( str.size() != dq.size() ) {
		char curLastChar = isReversed ? dq.front() : dq.back();

		if ( curLastChar == 'A' ) {
			if ( isReversed ) {
				dq.pop_front();
				continue;
			}
			dq.pop_back();
			continue;
		}
		
		if ( isReversed ) {
			dq.pop_front();
			isReversed = !isReversed;
			continue;
		}
		dq.pop_back();
		isReversed = !isReversed;
		continue;
	}
	string resString;
	
	while ( dq.size() ) {
		if ( !isReversed ) {
			resString += dq.front();
			dq.pop_front();
			continue;
		}
		resString += dq.back();
		dq.pop_back();
	}

	cout << (( str == resString ) ? 1 : 0) << endl;


    return 0;
}

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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int testCases; cin >> testCases;
	
	for ( int i = 0; i < testCases; i++ ) {
		string funcString; cin >> funcString;
		int sPointer = 0, ePointer; cin >> ePointer;
		ePointer --;
		int* curPointer = &sPointer;
		string numString; cin >> numString;
		vi nums;
		int tempNum = -1;

		for ( auto ns: numString ) {
			if ( '0' <= ns && ns <= '9' ) {
				if ( tempNum != -1 ) {
					tempNum *= 10;
					tempNum += ns - '0';
					continue;
				}
				tempNum = ns - '0';
				continue;
			}
			if ( tempNum != -1 ) {
				nums.push_back(tempNum);
			}
			tempNum = -1;
		}
		for ( auto f: funcString ) {
			if ( f == 'R' ) {
				if ( curPointer == &sPointer ) {
					curPointer = &ePointer;
					continue;
				}
				curPointer = &sPointer;
				continue;
			}
			if ( f == 'D' ) {
				if ( curPointer == &sPointer ) {
					(*curPointer) ++;
					continue;
				}
				(*curPointer) --;
			}
		}
		if ( sPointer - ePointer > 1 ) {
			cout << "error" << endl;
			continue;
		}
		cout << '[';
		if ( curPointer == &sPointer ) {
			for ( int i = sPointer; i <= ePointer; i++ ) {
				if ( i != sPointer ) cout << ',';
				cout << nums[i];
			}
			cout << ']' << endl;
			continue;
		}
		for ( int i = ePointer; i >= sPointer; i-- ) {
			if ( i != ePointer ) cout << ',';
			cout << nums[i];
		}
		cout << ']' << endl;
	}

    return 0;
}

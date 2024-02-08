#include <iostream>
#include <vector>
#include <cstring>

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
int blinking, len, mixCount, cycle = -1;
vector<char> existingStr, str;
vector<string> blinkingStrs;
string str1;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool IsSameVector(vector<char> v1, vector<char> v2) {
	int l = v1.size();
	for ( int i = 0; i < l; i++ ) {
		if ( v1[i] != v2[i] ) return 0;
	}
	return 1;
}
void DoBlink() {
	int i;
	vector<char> res;

	for ( i = 0; i < len; i+=2 ) {
		res.push_back(str[i]);
	}
	i -= ( len % 2 == 0 ) ? 1 : 3;
	for (; i > 0; i-=2 ) {
		res.push_back(str[i]);
	}
	str = res;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> blinking;

	cin >> str1;

	blinkingStrs.push_back(str1);
	existingStr = vector<char> (str1.begin(), str1.end());
	str = existingStr;
	len = existingStr.size();

	if ( len <= 2 ) {
		cout << str1 << endl;
		return 0;
	}

	mixCount = ((len % 2 == 0) ? (len/2 - 1) : (len/2));

	for ( int i = 0; i < 1000; i++ ) {
		DoBlink();
		blinkingStrs.push_back(string(str.begin(), str.end()));

		if ( IsSameVector(existingStr, str) ) {
			cout << "cycle :" << i + 1 << endl;
			cycle = ++i;
			break;
		}

	}
	if ( cycle == -1 ) {
		for ( auto s: str ) {
			cout << s;
		}
		cout << endl;
		return 0;
	}

	cout << blinkingStrs[blinking%cycle] << endl;
    return 0;
}

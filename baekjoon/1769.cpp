#include <iostream>
#include <algorithm>
#include <vector>

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
int l, c;
vector<pair<char, int>> str; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

int isVowel(char c) {
	if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) {
		return 1;
	}
	return 0;
}

bool comp(pair<char, int> a, pair<char, int> b) {
	return a.fi < b.fi;
}

void makePassword(vector<char> s, int head, int vowelCount) {
	int len = s.size();

	if ( len == l ) {
		if ( vowelCount >= 1 && len - vowelCount >= 2 ) {
			for ( auto ss: s ) {
				cout << ss;
			}
			cout << endl;
		}
		return;
	}

	vector<char> temp_vector;
	for ( int i = len ? head+1 : 0; i <= c - l + len; i++ ) {
		temp_vector = s;
		temp_vector.push_back(str[i].fi);
		makePassword(temp_vector, i, vowelCount + str[i].se);
	}
}

/* ----------------------------------------------- */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	if constexpr (local) 
		(void)!freopen("input.txt", "r", stdin);

	char temp;
	vector<char> empty;

	cin >> l >> c;

	for ( int i = 0; i < c; i++ ) {
		cin >> temp;
		str.push_back(make_pair(temp, isVowel(temp)));
	}

	sort(all(str), comp);

	makePassword(empty, 0, 0);

	return 0;
}

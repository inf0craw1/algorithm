#include <iostream>
#include <map>
#include <vector>
#include <cmath>

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
bool cmp(pair<char, int> a, pair<char, int> b) {
	if ( a.second == b.second ) return a.first > b.first;
	return a.second > b.second;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num;
	string temp;
	vector<string> strs;
	map<char, int> alphaScore;

	cin >> num;

	for ( int i = 0; i < 26; i++ ) {
		alphaScore.insert(make_pair('A' + i, 0));
	}
	
	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		strs.push_back(temp);

		int decimal = pow(10, (temp.size() - 1));
		for ( auto ss: strs[i] ) {
			alphaScore[ss] += decimal;
			decimal /= 10;
		}
	}
	sort(alphaScore.begin(), alphaScore.end(), cmp);

	for ( auto a: alphaScore ) {
		cout << a.fi << ' ' << a.se << endl;
	}
	


    return 0;
}

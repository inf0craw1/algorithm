#include <iostream>
#include <vector>
#include <cctype>
#include <map>

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

	int a, b;
	map<string, int> m;
	vector<string> v;

	v.push_back("");

	cin >> a >> b;

	for ( int i = 1; i <= a ; i++ ) {
		string temp;

		cin >> temp;

		v.push_back(temp);
		m.insert({temp, i});
	}

	for ( int i = 0; i < b; i++ ) {
		string temp;

		cin >> temp;

		if ( isdigit(temp[0]) ) {

			cout << v[stoi(temp)] << endl;
		} else {
			cout << m.find(temp)->second << endl;
		}
	}

    return 0;
}

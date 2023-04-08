#include <iostream>
#include <vector>
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

	int num, i = 0;
	map<int, int> m;

	cin >> num;

	vector<int> v(num, 0);

	for ( int i = 0; i < num; i++ ) {
		cin >> v[i];

		m.insert({v[i], 0});
	}


	for ( auto mm = m.begin(); mm != m.end(); mm++, i++ ) {
		mm->second = i;
	}

	for ( int i = 0; i < num; i++ ) {
		auto temp =  m.find(v[i]);
		if ( temp != m.end() ) {
			cout << temp->second << ' ';
		}
	}
	cout << endl;

    return 0;
}

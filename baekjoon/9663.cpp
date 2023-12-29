#include <iostream>
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
int num, cnt = 0; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int checkIsSafe(vector<int> v) {
	int size = v.size();
	int last = v[size - 1];

	for ( int i = 0; i < size - 1; i++ ) {
		if ( size - 1 - i == abs( last - v[i] )) return 0;
	}

	return 1;
}


void getCombination(vector<int> v) {
	
	int size = v.size();

	for ( int i = 0; i < size - 1; i++ ) {
		if ( v[i] == v[size - 1] ) {
			return;
		}
		if ( !checkIsSafe(v) ) return;
	}

	if ( v.size() ) {
		if ( v.size() == num ) {
			cnt ++;
			for ( auto vv: v ) {
				cout << vv << ' ';
			}
			cout << endl;
		}
	}

	for ( int i = 0; i < num; i++ ) {
		vector<int> newVec = v;
		newVec.push_back(i);
		getCombination(newVec);
	}

}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	vector<int> empty;
	
	cin >> num;

	getCombination(empty);
	
	cout << cnt << endl;

    return 0;
}

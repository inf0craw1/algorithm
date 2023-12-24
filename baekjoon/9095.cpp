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
int cnt = 0;
void getCombination(int num, int target) {
	if ( target == num ) {
		cnt++; 
	}
	if ( target < num ) return;
	getCombination(num+1, target);
	getCombination(num+2, target);
	getCombination(num+3, target);
}
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;
		cnt = 0;
		getCombination(0, temp);
		cout << cnt << endl;
	}

    return 0;
}

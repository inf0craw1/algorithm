#include <bits/stdc++.h>

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
int people[10000][15] = {};
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int getPeople(int k, int n) {
	if (people[k][n]) return people[k][n];
	people[k][n] = getPeople(k-1, n) + getPeople(k, n-1);

	return people[k][n];
}

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);
	
	int num, k, n;

	for ( int i = 0; i < 15; i++ ) {
		people[0][i] = i + 1;
	}
	for ( int i = 0; i < 10000; i++ ) {
		people[i][0] = 1;
	}

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> k >> n;

		cout << getPeople(k, n-1) << endl;
	}

    return 0;
}

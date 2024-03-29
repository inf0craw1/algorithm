#include <iostream>

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
	
	int n, m, arr[101] = {0};
	int target1, target2, temp;

	cin >> n >> m;

	for ( int i = 1; i < 101; i++ ) {
		arr[i] = i;
	}

	for ( int i = 0; i < m; i++ ) {
		cin >> target1 >> target2;
		
		temp = arr[target1];
		arr[target1] = arr[target2];
		arr[target2] = temp;
	}

	for ( int i = 1; i <= n; i++ ) {
		cout << arr[i] << ' ';
	}
	cout << endl;

    return 0;
}

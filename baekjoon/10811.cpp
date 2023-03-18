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
	
	for ( int i = 1; i <=100; i++ ) {
		arr[i] = i;
	}	

	cin >> n >> m;

	for ( int i = 0; i < m; i++ ) {
		cin >> target1 >> target2;

		int count = (target2 - target1) % 2 == 0 ? (target2 - target1) / 2 : (target2 - target1) / 2 + 1;

		for ( int j = 0; j < count; j++ ) {
			temp = arr[target1 + j];
			arr[target1 + j] = arr[target2 - j];
			arr[target2 - j] = temp;
		}

		for ( int i = 1; i <= n ; i++ ) {
			cout << arr[i] << ' ';
		}	
		cout << endl;
	}
	
	for ( int i = 1; i <= n ; i++ ) {
		cout << arr[i] << ' ';
	}
	cout << endl;

}

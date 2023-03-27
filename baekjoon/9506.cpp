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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n;

	for ( ;; ) {
		vector<int> arr;
		int sum = 0;
		
		cin >> n;

		if ( n == -1  ) break;

		for ( int i = 1; i < n; i++ ) {
			if ( n % i == 0 ) {
				sum += i;
				arr.push_back(i);
			}
		}

		if ( sum != n ) {
			cout << n << " is NOT perfect." << endl;
			continue;
		}
		cout << n << " = ";

		for ( auto num: arr ) {

			if ( num == arr[0] ) {
				cout << 1;
				continue;
			} 

			cout << " + " << num;
		}
		
		cout << endl;
	}
    return 0;
}

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

	int n, temp, maxi = 0;
	vector<int> arr;
	vector<int> increase, decrease;

	cin >> n;
	increase.resize(n, 1);
	decrease.resize(n, 1);
	for ( int i = 0; i < n; i++ ) {
		cin >> temp;

		arr.push_back(temp);
	}

	for ( int i = 0; i < n; i++ ) {

		for ( int j = 0; j < i; j++ ) {
			if ( arr[j] < arr[i] ) {
				increase[i] = max(increase[i], increase[j] + 1);
			}
		}

		for ( int j = n-1; j > n-i-1; j-- ) {
			if ( arr[n-1-i] > arr[j] ) {
				decrease[n-1-i] = max(decrease[n-1-i], decrease[j]+ 1);
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		maxi = max( maxi, increase[i] + decrease[i] );
	}
	cout << maxi-1 << endl;

    return 0;
}

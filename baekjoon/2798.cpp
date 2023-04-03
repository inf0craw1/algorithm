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

	int n, m, miniSum = 0;
	vector<int> arr;

	cin >> n >> m;

	for ( int i = 0; i < n; i++ ) {
		int temp;

		cin >> temp;
		arr.push_back(temp);
	}

	for ( int i = 0; i < n - 2; i++ ) {
		for ( int j = i + 1; j < n - 1; j++ ) {
			for ( int k = j + 1; k < n; k++ ) {
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > miniSum) {
					miniSum = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}

	cout << miniSum << endl;

    return 0;
}

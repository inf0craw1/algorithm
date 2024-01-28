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

	int n, temp, maxi = -2e9, mini = 0;
	vector<int> nums, acc;

	cin >> n;

	nums.push_back(0);
	acc.resize(n + 1, 0);
	
	for ( int i = 1; i <= n; i++ ) {
		cin >> temp;
		acc[i] = acc[i - 1] + temp;
		nums.push_back(temp);
		maxi = max(maxi, acc[i] - mini);
		mini = min(mini, acc[i]);
	}


	cout << maxi << endl;


    return 0;
}

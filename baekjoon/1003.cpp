#include <iostream>
#include <vector>
#include <string>

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
vector<int> zeros(41, 0), ones(41, 0);
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int getZeroFibo(int num) {
	if ( num <= 1 || zeros[num] != 0 ) return zeros[num];

	zeros[num] = getZeroFibo(num - 2) + getZeroFibo(num - 1);
	return zeros[num];
}
int getOneFibo(int num ) {

	if ( num <= 1 || ones[num] != 0 ) return ones[num];

	ones[num] = getOneFibo(num - 2) + getOneFibo(num - 1);
	return ones[num];
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int n, temp;
	cin >> n;

	zeros.resize(n+1, 0);
	ones.resize(n+1, 0);

	zeros[0]=1;
	zeros[1]=0;
	ones[0]=0;
	ones[1]=1;

	int res;

	for ( int i = 0; i < n; i++ ) {
		cin >> temp;

		getZeroFibo(temp);
		getOneFibo(temp);

		cout << zeros[temp] << ' ' << ones[temp] << endl;
		
	}

    return 0;
}

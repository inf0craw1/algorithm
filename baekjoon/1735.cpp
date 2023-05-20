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

int n[2], d[2];

/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void inputs() {
	cin >> n[0] >> d[0];
	cin >> n[1] >> d[1];
}

/* ----------------------------------------------- */

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
    	(void)!freopen("input.txt", "r", stdin);

	inputs();

	cout << n[0];
	cout << d[1];



   return 0;
}

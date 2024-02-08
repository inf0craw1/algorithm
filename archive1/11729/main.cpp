#include <iostream>
#include <cmath>

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
int n; 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
int GetRemainPole( int currentPole, int objectivePole ) {
	return 6 - currentPole - objectivePole;
}
void MoveTower(int currentPole, int objectivePole, int count) {
	if ( count == 0 ) return; 
	
	int remainPole = GetRemainPole(currentPole, objectivePole);
	MoveTower(currentPole, remainPole, count - 1);
	cout << currentPole << ' ' << objectivePole << endl;
	MoveTower(remainPole, objectivePole, count - 1);
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	int cnt = pow(2, n) - 1;

	cout << cnt << endl;

	MoveTower(1, 3, n);

    return 0;
}

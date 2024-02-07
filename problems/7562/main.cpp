#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

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
bool IsSafe(pii pos, int size) {
	if ( pos.fi < 0 || pos.fi >= size || pos.se < 0 || pos.se >= size ) return false;
	return true;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num, size;
	pii currentPos, objectivePos;
	vector<pii> directions = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

	cin >> num;

	for ( int z = 0; z < num; z++ ) {
		cin >> size;
		vector<vector<int>> mapp(size, vector<int> (size, 0));
		cin >> currentPos.fi >> currentPos.se >> objectivePos.fi >> objectivePos.se;
		if ( currentPos == objectivePos ) {
			cout << 0 << endl;
			continue;
		}
		queue<pii> q;
		q.push(currentPos);

		bool isFound = false;
		while ( q.size() && !isFound ) {
			pii currentPos = q.front();
			int currentStep = mapp[currentPos.fi][currentPos.se];
			q.pop();
		
			for ( int i = 0; i < directions.size(); i++ ) {
				pii newPos = make_pair(currentPos.fi + directions[i].fi, currentPos.se + directions[i].se);
				if ( !IsSafe(newPos, size) ) continue;
				if ( objectivePos == newPos ) {
					cout << currentStep + 1 << endl;
					isFound = true;
					break;
				}
				if ( mapp[newPos.fi][newPos.se] == 0 || mapp[newPos.fi][newPos.se] > currentStep + 1 ) {
					mapp[newPos.fi][newPos.se] = currentStep + 1;
					q.push(newPos);
				}
			}
		}
	}


    return 0;
}

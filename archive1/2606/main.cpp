#include <iostream>
#include <vector>
#include <queue>

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

	int computers, networks, computer1, computer2, res = -1;
	vector<int> chk;
	vector<vector<int>> graph;
	queue<int> q;

	cin >> computers >> networks;

	graph.resize(computers+1, vector<int> (computers+1, 0));
	chk.resize(computers+1, 0);

	for ( int i = 0; i < networks; i++ ) {
		cin >> computer1 >> computer2;
		graph[computer1][computer2] ++;
		graph[computer2][computer1] ++;
	}

	q.push(1);
	chk[1] ++;
	while( !q.empty() ) {
		int currentComputer = q.front();
		q.pop();
		res ++;

		for ( int i = 1; i <= computers; i++ ) {
			if ( graph[currentComputer][i] && !chk[i] ) {
				q.push(i);
				chk[i] ++;
			}
		}
	}

	cout << res << endl;

    return 0;
}

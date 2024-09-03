#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define fi first
#define se second
#define INF 0x7fffffff
#define LINF 0x7fffffffffffffff
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

/* - GLOBAL VARIABLES ---------------------------- */
int n;
vi colors;
map<int, int> m;
int res = INF;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

void DFS(int time, int acc) {

	if ( acc > res ) return;

	if ( time == n - 1 ) {
		res = min(res, acc);
		return;
	}

	for ( auto &n1: m ) { 
		int num1 = n1.fi;
		int num1Cnt = n1.se;

		if ( num1Cnt == 1 ) {
			m.erase(num1);
		} else {
			n1.se--;
		}

		for ( auto &n2: m ) {
			int num2 = n2.fi;
			int num2Cnt = n2.se;

			if ( num2Cnt == 1 ) {
				m.erase(num2);
			} else {
				n2.se--;
			}

			int newNum = num1 + num2;
			auto foundNewNum = m.find(newNum);
			int shouldErase = 0;

			if ( foundNewNum == m.end() ) {
				m.insert({newNum, 1});
				shouldErase = 1;
			} else {
				foundNewNum->se ++;
			}

			DFS(time+1, colors[time] ? acc : acc + num1 * num2);

			if ( shouldErase ) {
				m.erase(newNum);
			} else {
				foundNewNum->se --;
			}

			if ( num2Cnt == 1 ) {
				m.insert({num2, 1});
			} else {
				n2.se++;
			}
		}

		if ( num1Cnt == 1 ) {
			m.insert({num1, 1});
		} else {
			n1.se++;
		}
	}
}

/* ----------------------------------------------- */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	cin >> n;

	m.insert({1, n});

	for ( int i = 0; i < n-1; i++ ) {
		int color; cin >> color;
		colors.push_back(color);
	}

	vector<pi> vertices(n, {1, 1});

	int greedyRes = 0;

	for ( int i = 0; i < n - 1; i++ ) {
		if ( colors[i] ) {
			sort(all(vertices));
		} else {
			sort(rall(vertices));
		}

		pi back1 = vertices.back();
		vertices.pop_back();
		pi back2 = vertices.back();
		vertices.pop_back();

		if ( !colors[i] ) {
			back1.se --;
			back2.se --;
		}

		greedyRes += (back1.fi - back1.se) * (back2.fi - back2.se);
		
		vertices.push_back({back1.fi + back2.fi, back1.se + back2.se});
	}

	res = greedyRes;

	DFS(0, 0);

	cout << res << endl;


	return 0;
}

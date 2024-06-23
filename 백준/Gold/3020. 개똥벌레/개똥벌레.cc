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
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int width, height; cin >> width >> height;
	vi arr1(height+1, 0), arr2(height+1, 0);

	for ( int i = 0; i < width; i++ ) {
		int temp; cin >> temp;
		if ( i % 2 == 0 ) {
			arr1[temp]++;
			continue;
		}
		arr2[temp]++;
	}

	for ( int i = height-1; i >= 1; i-- ) {
		arr1[i] += arr1[i+1];
		arr2[i] += arr2[i+1];
	}
	
	priority_queue<int> pq;
	for ( int i = height; i >= 1; i-- ) {
		pq.push(-(arr1[i] + arr2[height - i + 1]));
	}

	int mini = INF, cnt = 0;

	while ( pq.size() ) {
		int cur = -pq.top();
		pq.pop();
		if ( cur < mini ) mini = cur;
		if ( cur > mini ) break;
		cnt ++;
	}

	cout << mini << ' ' << cnt << endl;

    return 0;
}

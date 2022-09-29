#include <bits/stdc++.h>

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
bool compareWithValue(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}
bool compareWithIndex(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int num, temp;
	vector<vector<int>> n;

	cin >> num;

	for ( int i = 0; i < num; i++ ) {
		cin >> temp;
		n.push_back({i, temp, 0});
	}
	sort(n.begin(), n.end(), compareWithValue);
	temp = 0;
	for( int i = 1; i < num; i++ ) {
		if ( n[i-1][1] != n[i][1] )	{
			n[i][2] = ++temp;
			continue;
		}
		n[i][2] = temp;
	}
	sort(n.begin(), n.end(), compareWithIndex);
	for ( int i = 0; i < num; i++ ) {
		cout << n[i][2] << ' ';
	}
	cout << endl;

    return 0;
}

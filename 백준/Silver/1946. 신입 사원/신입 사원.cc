#include <bits/stdc++.h>

#define debug if constexpr (local) std::cout
#define endl '\n'
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

#ifdef LOCAL
constexpr bool local = true;
#else
constexpr bool local = false;
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

	int cases; cin >> cases;

	for ( int i = 0; i < cases; i++ ) {
		int res = 0, lastGrade = 2e9;
		int numberOfApplicant; cin >> numberOfApplicant;
		vector<pi> grades;
		for ( int j = 0; j < numberOfApplicant; j++ ) {
			int a, b; cin >> a >> b;
			grades.push_back(make_pair(a, b));
		}
		sort(all(grades));
		for ( int j = 0; j < numberOfApplicant; j++ ) {
			if ( lastGrade < grades[j].se ) continue;
			res ++;
			lastGrade = grades[j].se;
		}
		cout << res << endl;
	}

    return 0;
}

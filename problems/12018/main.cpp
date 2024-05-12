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

	int res = 0;
	int numberOfSubject, mileage; cin >> numberOfSubject >> mileage;
	priority_queue<int> requiredMileages;

	for ( int i = 0; i < numberOfSubject; i++ ) {
		int curNum, maxNum; cin >> curNum >> maxNum;
		priority_queue<int> pq;
		
		for ( int j = 0; j < curNum; j++ ) {
			int temp; cin >> temp;
			pq.push(temp);
		}

		if ( curNum < maxNum ) {
			requiredMileages.push(-1);
			continue;
		}

		for ( int j = 0; j < maxNum-1; j++ ) {
			pq.pop();
		}
		int lastMileage = pq.top();
		requiredMileages.push(-(lastMileage));
	}

	while ( requiredMileages.size() ) {
		int curRequiredMileage = -requiredMileages.top();
		requiredMileages.pop();
		if ( mileage < curRequiredMileage ) {
			break;
		}	
		res++;
		mileage -= curRequiredMileage;
	}

	cout << res << endl;


    return 0;
}

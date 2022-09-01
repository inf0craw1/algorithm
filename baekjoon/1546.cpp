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
typedef numeric_limits<long double> ldbl;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int n, maxi = 0, temp;
    vector<long double> scores;
    long double avg = 0;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> temp;
        scores.push_back(temp);
        maxi = max(maxi, temp);
    }
    for ( int i = 0; i < n; i++ ) {
        avg += scores[i] / maxi * 100;
    }
    cout << avg / n << endl;

    return 0;
}


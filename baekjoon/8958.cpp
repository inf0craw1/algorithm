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
 
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */

/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    int n, count, answer = 0;
    string tmpStr;

    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> tmpStr;
        answer = 0;
        count = 0;
        for( int j = 0; j < tmpStr.length(); j++ ) {
            if ( tmpStr[j] == 'O') {
                answer += ++count;
                continue;
            }
            count = 0;
        }
        cout << answer << endl;
    }
    return 0;
}


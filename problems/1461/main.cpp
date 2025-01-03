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
typedef vector<vector<ll>> vvi;
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

    int books, bagSize; cin >> books >> bagSize;
    deque<int> dq;

    for ( int i = 0; i < books; i++ ) {
        int temp; cin >> temp;
        dq.push_back(temp);
    }

    sort(all(dq));

    for ( auto d: dq ) {
        cout << d << ' ';
    }
    cout << endl;
    cout << "---------------------" << endl;

    cout << "dq.front() : " << dq.front() << endl;
    cout << "dq.back() : " << dq.back() << endl;

    int curPos = 0; 
    int res = 0;

    while ( dq.size() ) {
        res += abs(curPos);
        curPos = 0;

        cout << " === return to zero res: " << res << endl;

        int direction = abs(dq.front()) > abs(dq.back()) ? -1 : 1;
        cout << "cur direction : " << direction << endl;

        for ( int i = 0; i < bagSize; i++ ) {
            if ( dq.empty() ) break;

            int nextBookPos = ( direction < 0 ) ? dq.front() : dq.back();
            cout << "nextBookPos: " << nextBookPos << endl;

            res += abs(nextBookPos - curPos);
            curPos = nextBookPos;

            cout << " ==== res : " << res << endl; 

            if ( direction < 0 ) {
                dq.pop_front();
                continue;
            }
            dq.pop_back();
        }
    }

    cout << res << endl;


    return 0;
}

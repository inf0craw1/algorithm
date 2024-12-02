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
string str;
int len;
/* ----------------------------------------------- */

/* - FUNCTIONS ----------------------------------- */
bool chkPoli(int cur) {
    if ( cur >= len ) return true;
    if ( str[cur] != 'X' ) return chkPoli(cur+1);
    int chk = 1;

    if ( cur + 3 < len ) {

        for ( int i = cur; i < cur+4; i++ ) {
            if ( str[i] != 'X' ) {
                chk = 0;
                break;
            }
        }
        if ( chk == 1 ) {
            for ( int i = cur; i < cur + 4; i++ ) {
                str[i] = 'A';
            }
            if ( chkPoli(cur+4) ) return true;
            for ( int i = cur; i < cur + 4; i++ ) {
                str[i] = 'X';
            }
        }
    }
    if ( cur + 1 < len ) {

        if ( str[cur] == 'X' && str[cur+1] == 'X' ) {
            str[cur] = 'B';
            str[cur+1] = 'B';
            if ( chkPoli(cur+2) ) return true;
            str[cur] = 'X';
            str[cur+1] = 'X';
        }
    }
    return false;
}
/* ----------------------------------------------- */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if constexpr (local) 
        (void)!freopen("input.txt", "r", stdin);

    cin >> str;
    len = str.size();

    if ( chkPoli(0) ) {
        cout << str << endl;
        return 0;
    }
    cout << -1 << endl;


    return 0;
}

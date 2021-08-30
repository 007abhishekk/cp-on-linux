#include<bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define sz(x) ((int)x.size())
template<typename T, typename U> inline void amin(T &a,U b) { a = (a > b ? b : a);}
template<typename T, typename U> inline void amax(T &a,U b) { a = (a > b ? a : b);}

#ifndef DEBUG_NOW
    #define debug(...) do {} while(0)
#else
    #include "debug.h"
#endif

void solve(){
    int n; cin >> n;
    char board[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    map<int,set<set<pii>>> wins;
    for(int i = 0; i < n; ++i) {
        set<pii> cells;
        bool ok = true;
        for(int j = 0; j < n; ++j) {
            if(board[i][j] == '.')
                cells.insert({i, j});
            ok &= (board[i][j] != 'O');
        }
        if(ok) 
            wins[sz(cells)].insert(cells);
        
        ok = true;
        cells.clear();
        for(int j = 0; j < n; ++j) {
            if(board[j][i] == '.')
                cells.insert({j, i});
            ok &= (board[j][i] != 'O');
        }
        if(ok) 
            wins[sz(cells)].insert(cells);
    }
    if(wins.empty()) {
        cout << "Impossible\n";
    } else {
        cout << wins.begin()->first << " " << wins.begin()->second.size() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    int tests = 1, id = 1; 
    cin >> tests;
    while(tests--){
    cout << "Case #" << id++ << ": ";
       solve(); 
    }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * DON'T GET STUCK ON ONE APPROACH
*/
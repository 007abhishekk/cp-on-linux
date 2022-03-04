// link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1159
#include<bits/stdc++.h>
using namespace std;
#define i64 int64_t
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

const int N = 1e5 + 5;
int f[N], sz[N];
template<typename T>
struct DSU{
    void init(int n) {
        for(int i = 0; i < n; ++i)
            f[i] = i,
            sz[i] = 1;
    }

    int root(int x) {
        while(x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y) {
        int a = root(x), b = root(y);
        if(a == b)
            return true;
        if(sz[a] > sz[b])
            swap(a, b);

        f[a] = b;
        sz[b] += sz[a];
        return false;
    }

    bool isConnected(int x, int y) {
        if(root(x) == root(y)) return true;
        else return false;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    DSU<int> d;
    d.init(n);
    vector<int> components[n];
    
    i64 ans = 1e18L;
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        d.merge(u, v);
    }

    if(d.isConnected(0, n - 1)) {
        cout << 0 << '\n';
        return;
    }
    
    for(int i = 0; i < n; ++i) {
        components[d.root(i)].push_back(i);
    }
    set<int> has1, hasN;
    int r0 = d.root(0);
    int rN = d.root(n - 1);
    for(int v: components[r0]) {
        has1.insert(v);
    }
    
    for(int v: components[rN]) {
        hasN.insert(v);
    }
    
    debug(has1);
    debug(hasN);
    for(int i = 0; i < n; ++i) {
        // choose this intermediate component
        i64 connect_1 = 1e5L, connect_n = 1e5L;
        for(int v: components[i]) {
            auto x = has1.lower_bound(v);
            if(x != has1.end()) amin(connect_1, abs(v - *x));
            if(x != has1.begin()) {
                --x;
                amin(connect_1, abs(v - *x));
            }
            auto y = hasN.lower_bound(v);
            if(y != hasN.end()) amin(connect_n, abs(v - *y));
            if(y != hasN.begin()) {
                --y;
                amin(connect_n, abs(v - *y));
            }
        }
        amin(ans, connect_1 * 1LL * connect_1 + connect_n * 1LL * connect_n);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    int tests = 1; 
    cin >> tests;
    while(tests--){
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
    * Try testing against a brute solution
*/
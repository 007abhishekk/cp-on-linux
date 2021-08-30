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

const int N = 56, lg = __lg(N) + 2;
vector<int> adj[N];
int par[N][lg], dist[N];
i64 pref[N];

int lca(int u, int v) {
   if(dist[u] < dist[v])
      swap(u, v);
   int diff = dist[u] - dist[v];
   while(diff > 0) {
      
      int j = __lg(diff);
      u = par[u][j];
      diff -= (1 << j);
   }
   if(u == v) {
      return u;
   }
   
   for(int i = lg - 1; i >= 0; --i) {
      int p_u = par[u][i], p_v = par[v][i];
      if(p_u != p_v and p_u != -1 and p_v != -1) {
         u = p_u;
         v = p_v;
      }
   }
   return par[u][0];
}

void dfs(int v, int p, i64 sum, vector<int> &c, int dis = 0) {
    par[v][0] = p;
    dist[v] = dis;
    pref[v] = c[v] + sum;
    for(int to: adj[v]) {
        if(to == p) continue;
        dfs(to, v, sum + c[v], c, dis + 1);
    }
}

void pre(int n) {
   for(int i = 1; i < lg; ++i) {
      for(int j = 0; j < n; ++j) {
         if(par[j][i - 1] == -1) continue;
         int p = par[j][i - 1];
         par[j][i] = par[p][i - 1];
      }
   }
}

void solve(){
    int n; cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        adj[i].clear();
    }

    if(n == 1) {
        cout << c[0] << '\n';
        return;
    }

    for(int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(par, -1, sizeof par);
    memset(dist, 0, sizeof dist);
    memset(pref, 0, sizeof pref);

    dfs(0, -1, 0, c);
    pre(n);

    vector<int> leaves;
    for(int i = 0; i < n; ++i) 
        if(sz(adj[i]) == 1)
            leaves.push_back(i);

    i64 ans = 0;
    for(int u: leaves) {
        for(int v: leaves) {
            if(!lca(u, v)) 
                amax(ans, pref[u] + pref[v] - pref[lca(u, v)]);
        }
    }
    cout << ans << '\n';
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
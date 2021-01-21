#include<bits/stdc++.h>
using namespace std;

const int N = 200200;
/* change dimension if required of *par* */
int par[N][21], dist[N];
vector<int> adj[N];

int lca(int u, int v) {
   if(dist[u] < dist[v])
      swap(u, v);
   int diff = dist[u] - dist[v];
   while(diff > 0) {
      
      int j = log2(diff);

      u = par[u][j];
      diff -= (1 << j);
   }
   if(u == v) {
      return u;
   }
   
   for(int i = 19; i >= 0; --i) {
      int p_u = par[u][i], p_v = par[v][i];
      if(p_u != p_v and p_u != -1 and p_v != -1) {
         u = p_u;
         v = p_v;
      }
   }
   return par[u][0];
}

void dfs(int v, int p, int dis = 0) {
   par[v][0] = p;
   dist[v] = dis;
   for(int z: adj[v]) {
      if(z != p) {
         dfs(z, v, dis + 1);
      }
   }
}

void pre(int n) {
   for(int i = 1; i < 20; ++i) {
      for(int j = 0; j < n; ++j) {
         if(par[j][i - 1] == -1) continue;
         int p = par[j][i - 1];
         par[j][i] = par[p][i - 1];
      }
   }
}

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int f[N], sz[N];
void init(int n) {
   for(int i = 0; i < n; ++i)
      f[i] = i,
      sz[i] = 1;
}

int root(int x) {
   while(x != f[x]) {
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
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define rep(var, start, end) for (int var = start; var < end; var++)

ll modularExponentiation(ll n, ll p, ll M)
{
   ll res = 1;
   while (p)
   {
      if (p & 1)
         res = (res * n) % M;
      n = (n * n) % M;
      p >>= 1;
   }
   return res;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   int a[n];
   rep(i, 0, n) cin >> a[i];
   deque<int> Q;
   rep(i, 0, k)
   {
      while (!Q.empty() && a[i] <= a[Q.back()])
         Q.pop_back();
      Q.push_back(i);
   }
   int i = k;
   while (i <= n)
   {
      cout << a[Q.front()] << ' ';
      while (!Q.empty() && Q.front() <= i - k)
         Q.pop_front();
      while (!Q.empty() && a[i] <= a[Q.back()])
         Q.pop_back();
      Q.push_back(i);
      i++;
   }
}

int main()
{
#ifdef LOCAL
   freopen("Contest/input.txt", "r", stdin);
   freopen("Contest/output.txt", "w", stdout);
#endif
   solve();
#ifdef LOCAL_DEFINE
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
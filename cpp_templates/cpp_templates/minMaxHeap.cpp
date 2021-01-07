#include <bits/stdc++.h>
using namespace std;
#define bs                      \
   ios::sync_with_stdio(false); \
   cin.tie(NULL);               \
   cout.tie(NULL)
#define ll long long int
#define pb push_back

#define rep(var, start, end) for (int var = start; var < end; var++)
#define erep(var, start, end) for (int var = start; var <= end; var++)
#define rrep(var, start, end) for (int var = start; var >= end; var--)

#define pa(x) cout << x << endl

#define pii pair<int, int>
#define pci pair<char, int>
#define pll pair<ll, ll>
#define test \
   int t;    \
   cin >> t; \
   while (t--)

template <typename... T>
void read(T &... args)
{
   ((cin >> args), ...);
}
ll modularExponentiation(ll x, ll n, ll M)
{
   if (n == 0)
      return 1;
   else if (n % 2 == 0)
      return modularExponentiation((x * x) % M, n / 2, M);
   return (x * modularExponentiation((x * x) % M, (n - 1) / 2, M)) % M;
}
template <class T>
T power(T n, T p)
{
   if (p == 0)
      return 1;
   else
      return power(n, p - 1) * n;
}
void max_heapify(int arr[], int i, int n)
{
   int Left = 2 * i, largest = i;
   int Right = 2 * i + 1;
   if (Left < n && arr[Left] > arr[i])
   {
      largest = Left;
   }
   else
   {
      largest = i;
   }
   if (Right < n && arr[Right] > arr[largest])
   {
      largest = Right;
   }
   if (largest != i)
   {
      int temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      max_heapify(arr, largest, n);
   }
}
void build_maxheap(int arr[], int n)
{
   rrep(i, n / 2, 1)
   {
      max_heapify(arr, i, n);
   }
}
void min_heapify(int arr[], int i, int n)
{
   int Left = 2 * i, smallest = i;
   int Right = 2 * i + 1;
   if (Left < n && arr[Left] < arr[i])
   {
      smallest = Left;
   }
   else
   {
      smallest = i;
   }
   if (Right < n && arr[Right] < arr[smallest])
      smallest = Right;
   if (smallest != i)
   {
      int temp = arr[i];
      arr[i] = arr[smallest];
      arr[smallest] = temp;
      min_heapify(arr, smallest, n);
   }
}
void build_minheap(int arr[], int n)
{
   rrep(i, n / 2, 1)
   {
      min_heapify(arr, i, n);
   }
}
void solve()
{
   int arr[] = {0, 4, 7, 8, 10, 11, 6, 5};
   int n = sizeof(arr) / sizeof(int);
   cout << n << endl;
   build_maxheap(arr, n);
   rep(i, 1, n)
   {
      cout << arr[i] << ' ';
   }
}
int main()
{
   bs;
   solve();
}
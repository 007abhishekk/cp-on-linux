#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define MOD 100000000
bool isPrime[MOD];
void sieve()
{
   isPrime[0] = 0;
   isPrime[1] = 1;
   for (int i = 4; i <= MOD; i += 2)
      isPrime[i] = 0, isPrime[i - 1] = 1;
   for (int i = 3; i * i <= MOD; i += 2)
   {
      if (isPrime[i])
      {
         for (int j = i * i; j <= MOD; j += 2 * i)
         {
            isPrime[j] = 0;
         }
      }
   }
}
int main()
{
   sieve();
}
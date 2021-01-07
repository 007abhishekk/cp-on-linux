#include<bits/stdc++.h>
using namespace std;
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
#define LOCAL_DEFINE
// #define LOCAL
#define deb(a) cout << #a << " = " << a << '\n'
#define deb2(a, b) cout << #a << " = " << a << ", " << #b << " = " << b << '\n'
#define rep(var,start,end) for(int var=start;var<end;var++)
#define erep(var,start,end) for(int var=start;var<=end;var++)
#define rrep(var,start,end) for(int var=start;var>=end;var--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pci pair<char,int>
#define pll pair<ll,ll>
#define test int t;cin>>t;while(t--)

ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
int a[50];
bool isSubsetSum(int target, int n){
    if(target == 0) return true;
    if(n == 0 && a[n] != target) return false;
    if(a[n] > target) return isSubsetSum(target, n - 1);
    else{
        return ( isSubsetSum(target - a[n], n - 1) || isSubsetSum(target, n - 1) );
    }
}
void solve(){
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    int SUM;
    cin >> SUM;
    cout << isSubsetSum(SUM, n);    
}

int main()
{
    bs;
    #ifdef LOCAL
    freopen("Contest/input.txt","r",stdin);
    freopen("Contest/output.txt","w",stdout);
    #endif
    //solve();
    test{
       solve(); 
    }
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
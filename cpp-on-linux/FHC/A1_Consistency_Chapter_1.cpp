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
    string s; cin >> s;
    vector<int> freq(26, 0);
    int cons = 0, vowel = 0;
    for(char c: s) freq[c - 'A']++;
    vowel += freq['A' - 'A'];
    vowel += freq['E' - 'A'];
    vowel += freq['I' - 'A'];
    vowel += freq['O' - 'A'];
    vowel += freq['U' - 'A'];
    cons = accumulate(all(freq), 0) - vowel;
    int ans = sz(s) * 2;
    for(int i = 0; i < 26; ++i) {
        char c = char('A' + i);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            amin(ans, (vowel - freq[i]) * 2 + cons);
        } else {
            amin(ans, (cons - freq[i]) * 2 + vowel);
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
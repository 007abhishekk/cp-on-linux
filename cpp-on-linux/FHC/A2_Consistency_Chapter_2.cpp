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

bool is_vowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int dist[26][26];

void solve(){
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
            dist[i][j] = 1e9;
        }
    }

    string s; cin >> s;
    int k; cin >> k;
    vector<int> freq(26, 0);
    for(char c: s) freq[c - 'A']++;
    for(int i = 0; i < k; ++i) {
        string p; cin >> p;
        dist[p[0] - 'A'][p[1] - 'A'] = 1;
    }

    for(int w = 0; w < 300; ++w) {
        for(int x = 0; x < 26; ++x) {
            for(int y = 0; y < 26; ++y) {
                for(int z = 0; z < 26; ++z) {
                    amin(dist[x][y], dist[x][z] + dist[z][y]);
                }
            }
        }
    }
    
    int ans = RAND_MAX;
    for(int i = 0; i < 26; ++i) {
        int here = 0;
        for(int j = 0; j < 26; ++j) {
            if(j == i || !freq[j]) continue;
            if(dist[j][i] == 1e9) {
                here = RAND_MAX; 
                break;
            }
            here += freq[j] * dist[j][i];
        }
        amin(ans, here);
        debug(i, ans);
    }
    cout << (ans == RAND_MAX ? -1 : ans) << '\n';
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
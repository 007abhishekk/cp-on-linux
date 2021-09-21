/* Problem Link: https://codeforces.com/contest/706/problem/D */
#include<bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define i32 int32_t
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define sz(x) ((int)x.size())
template<typename T, typename U> inline void amin(T &a,U b) { a = (a > b ? b : a);}
template<typename T, typename U> inline void amax(T &a,U b) { a = (a > b ? a : b);}

#ifndef DEBUG_NOW
    #define debug(...) do {} while(0)
#else
    #include "debug.h"
#endif

#define CHILDREN 2
#define MSB 30

class Trie{
private:
    struct TrieNode{
        TrieNode* children[CHILDREN];
        int cnt = 0;
        TrieNode() {
            for(int i = 0; i < CHILDREN; ++i) {
                children[i] = nullptr;
            }
        }
        ~TrieNode() {
            for(int i = 0; i < CHILDREN; ++i) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    Trie(): root(new TrieNode()) {}
    ~Trie() {
        delete root;
        root = nullptr;
    }

    void insert(int key) {
        TrieNode* head = root;
        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            if(!head->children[bit]) {
                head->children[bit] = new TrieNode();
            }
            head = head->children[bit];
            head->cnt++;
        }
    }

    int query(int key) {
        int XOR = 0;
        TrieNode *head = root;
        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            if(head->children[!bit] && head->children[!bit]->cnt > 0) {
                head = head->children[!bit];
                XOR |= (1 << i);
            }
            else if(head->children[bit]){
                head = head->children[bit];
            }
        }
        return XOR;
    }

    void remove(int key) {
        TrieNode* head = root;
        for(int i = MSB; i >= 0; --i) {
            bool bit = (bool)(key & (1 << i));
            head = head->children[bit];
            head->cnt--;
        }
    }
};

void solve(){
    Trie trie;
    int n; cin >> n;
    map<int,int> f;
    trie.insert(0);
    for(int i = 0; i < n; ++i) {
        char op; cin >> op;
        int num; cin >> num;
        if(op == '+') {
            f[num]++;
            if(f[num] == 1)
                trie.insert(num);
        } else if(op == '-') {
            --f[num];
            if(f[num] == 0) {
                trie.remove(num);
            }
        } else {
            cout << trie.query(num) << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
    int tests = 1; 
    // cin >> tests;
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
*/
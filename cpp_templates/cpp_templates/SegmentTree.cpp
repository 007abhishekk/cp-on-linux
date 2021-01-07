#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int N = 100100;
ll seg[4*N];

struct SegmentTree{
    void init() {
        memset(seg, 0, sizeof(seg));
    }

    void build(int node, int l, int r, int a[]) {
        if(l == r) {
            seg[node] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(2*node + 1, l, m, a);
        build(2*node + 2, m+1, r, a);
        seg[node] = seg[2*node + 1] + seg[2*node + 2];
    }
    void update(int node, int i, int val, int l, int r) {
        if(l == r) {
            seg[node] = val;
            return;
        }
        int m = (l + r) >> 1;
        if(i <= m)
            update(2*node + 1, i, val, l, m);
        else update(2*node + 2, i, val, m+1, r);
        seg[node] = seg[2*node + 1] + seg[2*node + 2];
    }
    int query(int node, int sl, int sr, int ql, int qr) {
        if(sl > qr or sr < ql)
            return 0;
        if(sl >= ql and sr <= qr)
            return seg[node];
        int m = (sl + sr) >> 1;
        int l = query(2*node + 1, sl, m, ql, qr);
        int r = query(2*node + 2, m+1, sr, ql, qr);
        return (l + r);
    }
};

int main() {
    SegmentTree tree;
    
}
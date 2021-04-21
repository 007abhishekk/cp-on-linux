#include<bits/stdc++.h>
using namespace std;

/* TODO: make more generic, STILL IN PROGRESS */
template<typename T>
struct SegmentTree {

private:
    struct Node {
        int mx, mn, sum;
        Node operator +(Node const &a) {
            return {max(mx, sum + a.mx), min(mn, sum + a.mn), sum + a.sum};
        }
        Node merge(Node x, Node y) {
            return (x + y);
        }
    };
    
public: 
    vector<Node> seg;
    vector<T> a;
    SegmentTree (int n): seg(4*n), a(n) {} 
    Node combine(int node) {
        return Node().merge(seg[(node << 1) + 1], seg[(node << 1) + 2]);
    }
    void build(int node, int L, int R) {
        if(L == R) {
            seg[node].sum = a[L];
            seg[node].mx = max(a[L], 0);
            seg[node].mn = min(a[L], 0);
            return;
        }

        int m = (L + R) >> 1;
        build(2*node + 1, L, m);
        build(2*node + 2, m+1, R);
        seg[node] = combine(node);
    }
    void update(int node, int i, int val, int L, int R) {
        if(L == R) {
            seg[node].sum = v;
            seg[node].mx = max(v, 0);
            seg[node].mn = min(v, 0);
            return;
        }

        int m = (L + R) >> 1;
        if(i <= m)  
            update(2*node + 1, i, v, L, m);
        else update(2*node + 2, i, v, m+1, R);
        seg[node] = combine(node);
    }
    Node query(int node, int L, int R, int ql, int qr) {
        if(L > qr or R < ql)
            return {0, 0, 0};
        if(L >= ql and R <= qr)
            return seg[node];
        int m = (L + R) >> 1;
        Node l = query(2*node + 1, L, m, ql, qr);
        Node r = query(2*node + 2, m+1, R, ql, qr);
        return Node{}.merge(l, r);
    }
};

int main() {
    SegmentTree<int> tree();
    
}
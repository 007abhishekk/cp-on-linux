#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define i32 int32_t
#define ll long long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(x) ((int)x.size())
template <typename T, typename U> inline void amin(T &a, U b){ a = (a > b ? b : a); }
template <typename T, typename U> inline void amax(T &a, U b){ a = (a > b ? a : b); }

#ifndef DEBUG_NOW
#define debug(...) do {} while (0)
#else
#include "debug.h"
#endif

/* TODO: Fix bugs [with struct, seg tree operations, ..] */
/* TODO: 
    modify 'Node' according to problem
    modify access variables according to 'Node'
    modify constructors
 */
template <typename T>
struct SegmentTree
{

private:
    struct Node
    {
        i64 sum = 0;
        Node(i64 x): sum(x){} 
        Node operator +(Node const &a) {
            return {sum + a.sum};
        }
        Node merge(Node x, Node y)
        {
            return (x + y);
        }
    };
    vector<Node> seg, lazy;
    /* why??? */
    vector<T> a;
    /* modify combine function */
    Node combine(int node)
    {
        return Node().merge(seg[(node << 1) + 1], seg[(node << 1) + 2]);
    }

public:
    SegmentTree(int n) : seg(4 * n), lazy(4 * n), a(n) {}
    /* remove/keep vector */
    void build(int node, int L, int R, vector<T> &b)
    {
        if (L == R)
        {
            seg[node].sum = b[L];
            return;
        }

        int m = (L + R) >> 1;
        build(2 * node + 1, L, m);
        build(2 * node + 2, m + 1, R);
        seg[node] = combine(node);
    }
    void update(int node, int L, int R, int ul, int ur, int val)
    {
        if (lazy[node].sum)
        {
            seg[node].sum += 1LL * (R - L + 1) * lazy[node].sum;
            if (L != R)
            {
                lazy[2 * node + 1].sum += lazy[node].sum;
                lazy[2 * node + 2].sum += lazy[node].sum;
            }
            lazy[node].sum = 0;
        }
        if (L > R || L > ur || R < ul)
            return;
        if (L >= ul && R <= ur)
        {
            seg[node].sum += 1LL * (R - L + 1) * val;
            if (L != R)
            {
                lazy[2 * node + 1].sum += val;
                lazy[2 * node + 2].sum += val;
            }
            return;
        }
        int m = (L + R) >> 1;
        update(2 * node + 1, L, m, ul, ur, val);
        update(2 * node + 2, m + 1, R, ul, ur, val);
        seg[node] = combine(node);
    }
    Node query(int node, int L, int R, int ql, int qr)
    {
        /* update default return */
        if (L > R || L > qr || R < ql)
            return Node(0);
        if (lazy[node].sum)
        {
            seg[node].sum += 1LL * (R - L + 1) * lazy[node].sum;
            if (L != R)
            {
                lazy[2 * node + 1].sum += lazy[node].sum;
                lazy[2 * node + 2].sum += lazy[node].sum;
            }
            lazy[node].sum = 0;
        }

        int m = (L + R) >> 1;
        if (L >= ql and R <= qr)
            return seg[node];
        Node Left = query(2 * node + 1, L, m, ql, qr);
        Node Right = query(2 * node + 2, m + 1, R, ql, qr);
        return Node{}.merge(Left, Right);
    }
};

int main() {}
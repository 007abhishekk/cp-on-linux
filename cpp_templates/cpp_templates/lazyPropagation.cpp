#include<bits/stdc++.h>
using namespace std;
#define bs ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
const int N = 100100;
ll seg[4*N], lazy[4*N];
void build(int node, int l,int r, ll a[]){
	lazy[node] = 0;
    if(l == r){
        seg[node] = a[l];
		return;
    }
	int m = (l+r) >> 1;
	//left
	build(2*node + 1, l, m, a);
	//right
	build(2*node + 2, m + 1, r, a);
	//fill
	seg[node] = seg[2*node + 1] + seg[2*node + 2];
}
void update(int node,int l, int r, int ul, int ur, ll val){
	if(lazy[node]){
		seg[node] += 1ll*(r - l + 1)*lazy[node];
		if(l != r){
			lazy[2*node + 1] += lazy[node];
			lazy[2*node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(l > r || l > ur || r < ul)
		return;
	if(l >= ul && r <= ur){
		seg[node] += 1ll*(r - l + 1)*val;
		if(l != r){
			lazy[2*node + 1] += val;
			lazy[2*node + 2] += val;
		}
		return;
	}
	int m = l + r >> 1;
	update(2*node + 1, l, m, ul, ur, val);
	update(2*node + 2, m+1, r, ul, ur, val);
	seg[node] = seg[2*node + 1] + seg[2*node + 2];
}
ll query(int node, int sl,int sr, int ql, int qr){
	if(sl > sr || sl > qr || sr < ql)
		return 0;
	if(lazy[node]){
		seg[node] += 1ll*(sr - sl + 1)*lazy[node];
		if(sl != sr){
			lazy[2*node + 1] += lazy[node];
			lazy[2*node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}

    if(sl >= ql && sr <= qr){
		return seg[node];
    }
    int m = (sl + sr) >> 1;
    ll l = query(2*node + 1, sl, m, ql, qr);
    ll r = query(2*node + 2, m + 1, sr, ql, qr);
    return (l+r);
}
int main()
{
    bs;
        
}
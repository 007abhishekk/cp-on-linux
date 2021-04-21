#include <bits/stdc++.h>
using namespace std;
/* 1-based index fenwick tree */
const int N = (1 << 20) + 1;
int fenw[N];

void update(int i, int val) {
    for(; i < N; i += i&(-i))
        fenw[i] += val;
}

int sum(int r) {
    int tot = 0;
    for(;r > 0; r -= r&(-r))
        tot += fenw[r];
    return tot;
}

int getSum(int l,int r) {
    return sum(r) - sum(l - 1);
}

int kth(int k) {
    int idx = 0, sum = 0;
    for(int i = 20; i >= 0; --i) {
        if(fenw[idx + (1 << i)] + sum < k) {
            idx += (1 << i);
            sum += fenw[idx];
        } 
    }
    return idx + 1;
}

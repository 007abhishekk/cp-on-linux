#include <bits/stdc++.h>
using namespace std;
#define bs                       \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define ll long long int
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

template <typename T>
void read(T &a)
{
    cin >> a;
}
template <typename T, typename T0>
void read(T &a, T0 &b)
{
    cin >> a >> b;
}

const int N = 1002, inf = 1e9;
int h, w, vis[N][N], dist[N][N];
string s[N];
int dx[] = {-1, 1};
bool check(int x1, int y1, int x2, int y2)
{
    return (s[x1][y1] != s[x2][y2]);
}
void _01bfs()
{
    dist[0][0] = 0;
    deque<pii> dq;
    dq.push_front({0, 0});
    while (!dq.empty())
    {
        pii v = dq.front();
        dq.pop_front();
        if (vis[v.first][v.second] == 1)
            continue;
        vis[v.first][v.second] = 1;
        for (int i = 0; i < 2; ++i)
        {
            int x = v.first + dx[i], y = v.second;
            if (x < 0 or x >= h)
                continue;
            int inc = check(v.first, v.second, x, y);
            if (dist[v.first][v.second] + inc < dist[x][y])
                dist[x][y] = dist[v.first][v.second] + inc;
            if (inc)
            {
                dq.push_back({x, y});
            }
            else
            {
                dq.push_front({x, y});
            }
        }
        for (int i = 0; i < 2; ++i)
        {
            int y = v.second + dx[i], x = v.first;
            if (y < 0 or y >= w)
                continue;
            int inc = check(v.first, v.second, x, y);
            if (dist[v.first][v.second] + inc < dist[x][y])
                dist[x][y] = dist[v.first][v.second] + inc;
            if (inc)
            {
                dq.push_back({x, y});
            }
            else
            {
                dq.push_front({x, y});
            }
        }
    }
}
void init()
{
    for (int i = 0; i < h; ++i)
    {
        s[i].clear();
        rep(j, 0, w)
        {
            vis[i][j] = 0;
            dist[i][j] = inf;
        }
    }
}
void solve()
{
    read(h, w);
    init();
    for (int i = 0; i < h; ++i)
    {
        cin >> s[i];
    }
    _01bfs();
    cout << ((dist[h - 1][w - 1] == inf) ? -1 : dist[h - 1][w - 1]) << '\n';
}

int main()
{
    bs;
    test
    {
        solve();
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
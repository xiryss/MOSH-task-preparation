#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <time.h>
#include <ctime>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <complex>
#include <chrono>
#include <unordered_set>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define pbc push_back
#define pob pop_back()
#define vin(a) for (auto& i : a) cin >> i
#define sp system("pause")
#define mp make_pair
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y)
{
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y)
{
    if (x < y) x = y;
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ld asdasdcl = 0;
double getTime() { return (clock() - asdasdcl) / (double)CLOCKS_PER_SEC; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    return { a.first - b.first, a.second - b.second };
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    return { a.first + b.first, a.second + b.second };
}
/*
#define getchar_unlocked _getchar_nolock
inline int readInt()
{
    char x;
    while (x = getchar_unlocked())
    {
        if (x >= '0' && x <= '9')
        {
            int ans = x - '0';
            while (x = getchar_unlocked())

            {
                if (!(x >= '0' && x <= '9')) return ans;
                ans = ans * 10 + x - '0';
            }
        }
    }
}*/
/*using namespace __gnu_pbds;

using ordered_set = tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;*/
const int inf = 1e9 + 228;
const ld EPS = 1e-25;
const ld PI = acos(-1.0);
int mod = 998244353;
const ld INF = 3e18;
const int MAXN = 1007;
ll a[MAXN][MAXN];
struct par
{
    char a, b, c;
};
ll calctriple(vector<int>& p, int id) {
    int f = id * 3, s = id * 3 + 1, t = id * 3 + 2;
    return a[p[f]][p[s]] * a[p[f]][p[t]] * a[p[s]][p[t]];
}
ll calcscore(vector<int>& p) {
    ll sc = 0;
    for (int i = 0; i < p.size() / 3; ++i) {
        sc += calctriple(p, i);
    }
    return sc;
}
vector<int> comp;
vector<vector<int>> tempans;
int used[MAXN];
int n;

void dfs(int v) {
    used[v] = 1;
    comp.pbc(v);
    for (int i = 0; i < n; ++i) {
        if (a[i][v] && !used[i]) {
            dfs(i);
        }
    }
}
signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    ll bs = -1;
    vector<int> p(n);
    iota(all(p), 0);
    vector<int> bp = p;
    shuffle(all(bp), rnd);
    bs = calcscore(bp);
    ll tsc = bs;
    auto tcl = clock();
    p = bp;
    for (int pairs = 1; pairs <= 4; ++pairs) {
        tsc = calcscore(p);
        for (int i = 0; ; i++) {
            if ((ld)(clock() - tcl) / CLOCKS_PER_SEC > 20.0 * pairs) {
                break;
            }
            auto tp = p;
            ll tempscore = tsc;
            vector<pair<int, int>> ps;
            for (int j = 0; j < 1; ++j) ps.pbc({ rnd() % n, rnd() % n });
            for (auto j : ps) {
                tempscore -= calctriple(tp, j.first / 3);
                tempscore -= calctriple(tp, j.second / 3);
            }
            for (auto j : ps) {
                swap(tp[j.first], tp[j.second]);
            }
            for (auto j : ps) {
                tempscore += calctriple(tp, j.first / 3);
                tempscore += calctriple(tp, j.second / 3);
            }
            if (tempscore > tsc) {
                p = tp;
                tsc = tempscore;
            }
            if (tempscore > bs) {
                bp = tp;
                tsc = tempscore;
                bs = tempscore;
                p = tp;
                cerr << "UPD " << bs << " pairs = " << pairs << '\n';
            }
            else {
                continue;
            }
        }
    }
    for (int i = 0; i < bp.size(); i += 3) {
        cout << bp[i] + 1 << ' ' << bp[i + 1] + 1 << ' ' << bp[i + 2] + 1 << '\n';
    }
    //  sp;
}

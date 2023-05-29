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
    if (n <= 24) {
        vector<ll> dp(1 << n, -1e18);
        vector<par> p(1 << n);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] < 0) continue;
            int sbt = 0;
            for (int i = 0; i < n; ++i) {
                if (!((mask >> i) & 1)) {
                    sbt = i;
                    break;
                }
            }
            for (int nb = sbt + 1; nb < n; ++nb) {
                for (int tb = nb + 1; tb < n; ++tb) {
                    if (((mask >> nb) & 1)) continue;
                    if (((mask >> tb) & 1)) continue;
                    ll& nw = dp[mask | (1 << sbt) | (1 << nb) | (1 << tb)];
                    int msk = mask | (1 << sbt) | (1 << nb) | (1 << tb);
                    if (nw < dp[mask] + 1ll * a[nb][sbt] * a[nb][tb] * a[sbt][tb]) {
                        p[msk] = { (char)sbt, (char)nb, (char)tb };
                        nw = dp[mask] + 1ll * a[nb][sbt] * a[nb][tb] * a[sbt][tb];
                    }
                }
            }
        }
        cerr << "score = " << dp[(1 << n) - 1] << '\n';
        int msk = (1 << n) - 1;
        while (msk) {
            auto kek = p[msk];
            cout << (int)(kek.a + 1) << ' ' << (int)(kek.b + 1) << ' ' << (int)(kek.c + 1) << '\n';
            msk ^= (1 << kek.a);
            msk ^= (1 << kek.b);
            msk ^= (1 << kek.c);
        }
        return 0;
    }
    vector<vector<int>> comps;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            comp.clear();
            dfs(i);
            comps.pbc(comp);
        }
    }
    int mxs = 0;
    bool perc = 1;
    for (auto i : comps) {
        perc &= (i.size() % 3 == 0);
        mxs = max(mxs, (int)i.size());
    }
    if (mxs <= 18 && perc) {
        ll tots = 0;
        for (auto cmp : comps) {
            vector<ll> dp(1 << cmp.size(), -1e18);
            vector<par> p(1 << cmp.size());
            dp[0] = 0;
            for (int mask = 0; mask < (1 << cmp.size()); ++mask) {
                if (dp[mask] < 0) continue;
                int sbt = 0;
                for (int i = 0; i < cmp.size(); ++i) {
                    if (!((mask >> i) & 1)) {
                        sbt = i;
                        break;
                    }
                }
                for (int nb = sbt + 1; nb < cmp.size(); ++nb) {
                    for (int tb = nb + 1; tb < cmp.size(); ++tb) {
                        if (((mask >> nb) & 1)) continue;
                        if (((mask >> tb) & 1)) continue;
                        ll& nw = dp[mask | (1 << sbt) | (1 << nb) | (1 << tb)];
                        int msk = mask | (1 << sbt) | (1 << nb) | (1 << tb);
                        if (nw < dp[mask] + 1ll * a[cmp[nb]][cmp[sbt]] * a[cmp[nb]][cmp[tb]] * a[cmp[sbt]][cmp[tb]]) {
                            p[msk] = { (char)sbt, (char)nb, (char)tb };
                            nw = dp[mask] + 1ll * a[cmp[nb]][cmp[sbt]] * a[cmp[nb]][cmp[tb]] * a[cmp[sbt]][cmp[tb]];
                        }
                    }
                }
            }
            tots += dp[(1 << cmp.size()) - 1];
            int msk = (1 << cmp.size()) - 1;
            while (msk) {
                auto kek = p[msk];
                cout << (int)(cmp[kek.a] + 1) << ' ' << (int)(cmp[kek.b] + 1) << ' ' << (int)(cmp[kek.c] + 1) << '\n';
                msk ^= (1 << kek.a);
                msk ^= (1 << kek.b);
                msk ^= (1 << kek.c);
            }
        }
        cerr << "Score = " << tots << endl;
        return 0;
    }
    ll bs = -1;
    vector<int> p(n);
    iota(all(p), 0);
    vector<int> bp = p;
    bp.clear();
    if (perc && comps.size()  > 1) {
        ll tot = 0;
        for (auto i : comps) {
            ll bsc = -1;
            vector<int> bestc;
            for (int step = 0; step < 100; ++step) {
                vector<int> tperm = i;
                vector<int> used(i.size());
                shuffle(all(tperm), rnd);
                vector<int> collect;
                ll sscore = 0;
                for (int j = 0; j < i.size(); ++j) {
                    if (used[j]) continue;
                    ll bpts = -1;
                    int x1, y1;
                    for (int x = j + 1; x < i.size(); ++x) {
                        if (used[x]) continue;
                        for (int y = x + 1; y < i.size(); ++y) {
                            if (used[y]) continue;
                            if (a[tperm[j]][tperm[x]] * a[tperm[x]][tperm[y]] * a[tperm[j]][tperm[y]] > bpts) {
                                x1 = x, y1 = y;
                                bpts = a[tperm[j]][tperm[x]] * a[tperm[x]][tperm[y]] * a[tperm[j]][tperm[y]];
                            }
                        }
                    }

                    collect.pbc(tperm[j]);
                    collect.pbc(tperm[x1]);
                    collect.pbc(tperm[y1]);
                    used[j] = 1;
                    used[x1] = 1;
                    used[y1] = 1;
                    sscore += bpts;
                }
                if (sscore > bsc) {
                    bestc = collect;
                    bsc = sscore;
                }
            }
            for (int j : bestc)bp.pbc(j);
        }
        bs = calcscore(bp);
        cerr << "UPD " << bs << " pairs = " << 0 << '\n';
    }
    else {
        for (int step = 0; step < 30; ++step) {
            vector<int> tbp;
            ll tscore = 0;
            vector<int> tperm(n);
            vector<int> used(n);

            iota(all(tperm), 0);
            shuffle(all(tperm), rnd);
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                ll bpts = -1;
                int  j1, x1;
                for (int j = i + 1; j < n; ++j) {
                    if (used[j]) continue;
                    for (int x = j + 1; x < n; ++x) {
                        if (used[x]) continue;
                        if (a[tperm[j]][tperm[i]] * a[tperm[j]][tperm[x]] * a[tperm[i]][tperm[x]] > bpts) {
                            bpts = a[tperm[j]][tperm[i]] * a[tperm[j]][tperm[x]] * a[tperm[i]][tperm[x]];
                            j1 = j, x1 = x;
                        }
                    }
                }
                used[i] = 1;
                used[j1] = 1;
                used[x1] = 1;
                tbp.pbc(tperm[i]);
                tbp.pbc(tperm[j1]);
                tbp.pbc(tperm[x1]);
                tscore += bpts;
            }
            if (tscore > bs) {
                bs = tscore;
                bp = tbp;
                cerr << "UPD " << bs << " pairs = " << 0 << '\n';
            }
        }
    }
    ll tsc = bs;
    auto tcl = clock();
    p = bp;
    for (int pairs = 1; pairs <= 4; ++pairs) {
        //shuffle(all(p), rnd);
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
            /* int val = f(u);
             if (val > ans || rnd() < exp((val - ans) / t)) {
                 v = u;
                 ans = val;
             }*/
        }
    }
    for (int i = 0; i < bp.size(); i += 3) {
        cout << bp[i] + 1 << ' ' << bp[i + 1] + 1 << ' ' << bp[i + 2] + 1 << '\n';
    }
    //  sp;
}

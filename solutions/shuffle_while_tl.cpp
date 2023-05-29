
#define _CRT_SECURE_NO_WARNINGS

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
ll getscore(vector<int>& p) {
    ll sc = 0;
    for (int i = 0; i < p.size(); i += 3) {
        sc += a[p[i]][p[i + 1]] * a[p[i + 1]][p[i + 2]] * a[p[i]][p[i + 2]];
    }
    return sc;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> p(n);
    iota(all(p), 0);
    vector<int> bestp;
    ll bc = -1;
    while (clock() / CLOCKS_PER_SEC < 14.5) {
        shuffle(all(p), rnd);
        if (getscore(p) > bc) {
            bc = getscore(p);
            bestp = p;
        }
    }
    for (int i = 0; i < bestp.size(); i += 3) {
        cout << bestp[i] + 1 << ' ' << bestp[i + 1] + 1 << ' ' << bestp[i + 2] + 1 << '\n';
    }
    //  sp;
}